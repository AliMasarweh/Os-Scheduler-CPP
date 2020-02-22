//
// Created by ali-masa on 2/21/20.
//

#include <time.h>
#include "scheduler.h"

using namespace std;

vector<vector<Task*> >
        Scheduler::s_tasksByPriority = Scheduler::initTasksContainer();

const Time& Scheduler::currentTime() {
    return s_time;
}

void Scheduler::addTask(Task &t)
{
    unsigned char taskPriority = t.getPriority();
    s_tasksByPriority[taskPriority].push_back(&t);
}

Time Scheduler::runAllTasks() {
    Time totalRunningTime(0);
    int clockPerSecToMilliSec = 1000;

    for(unsigned char i = s_highestPriority-1; i >= 0; --i)
    {
        vector<Task *> tasks = s_tasksByPriority[i];
        for(size_t j = 0; j < tasks.size(); ++j)
        {
            Task * task = tasks.at(i);
            clock_t time = clock();
            task->run();
            totalRunningTime += (clock() - time)/
                    CLOCKS_PER_SEC*clockPerSecToMilliSec;
        }
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

