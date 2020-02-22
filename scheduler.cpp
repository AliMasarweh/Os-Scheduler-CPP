//
// Created by ali-masa on 2/21/20.
//

#include <time.h>
#include "scheduler.h"
#include "task.h"

using namespace std;

Time Scheduler::s_time = Time();
size_t Scheduler::s_numberOfTasks = 0;
vector<vector<Task*> >
        Scheduler::s_tasksByPriority = Scheduler::initTasksContainer();

const Time& Scheduler::currentTime() {
    return s_time;
}

void Scheduler::addTask(Task &t)
{
    unsigned char taskPriority = t.getPriority();
    s_tasksByPriority[taskPriority].push_back(&t);
    ++s_numberOfTasks;
}

Time Scheduler::runAllTasks() {
    Time totalRunningTime(0);
    int clockPerSecToMilliSec = 1000;

    for (unsigned char i = s_highestPriority - 1; s_numberOfTasks; --i)
    {
        vector<Task *> tasks = s_tasksByPriority.at(i);
        for (size_t j = 0; s_numberOfTasks && j < tasks.size();)
        {
            Task *task = tasks.at(j);
            if (task->getNextRunPeriod() > 0)
            {
                clock_t time = clock();
                task->run();
                totalRunningTime +=
                        (clock() - time) /
                        (CLOCKS_PER_SEC * clockPerSecToMilliSec);
                tasks.erase(tasks.begin() + j);
                --s_numberOfTasks;
            } else
                ++j;

        }
        i = i%s_highestPriority? i: s_highestPriority;
    }

    return totalRunningTime;
}

vector<vector<Task *> > Scheduler::initTasksContainer() {
    vector<vector<Task *> > ans(s_highestPriority);

    for(unsigned char i = 0; i < s_highestPriority; ++i)
    {
        ans.push_back(vector<Task *>());
    }

    return ans;
}

