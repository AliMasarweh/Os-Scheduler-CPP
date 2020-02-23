//
// Created by ali-masa on 2/21/20.
//

#include <time.h>
#include <unistd.h>
#include "scheduler.h"
#include "task.h"

using namespace std;

Time Scheduler::s_time = Time();
size_t Scheduler::s_numberOfTasks = 0;
priority_queue<Task*, vector<Task*>,
        greater<Task*> > Scheduler::s_prioritizedTasks;

const Time& Scheduler::currentTime() {
    return s_time;
}

void Scheduler::addTask(Task &t)
{
    s_prioritizedTasks.push(&t);
    ++s_numberOfTasks;
}

Time Scheduler::runAllTasks() {
    Time totalRunningTime(0);
    int clockPerSecToMilliSec = 1000;

    while(!Scheduler::s_prioritizedTasks.empty())
    {
        Task *task = s_prioritizedTasks.top();
        s_prioritizedTasks.pop();
        if (task->getNextRunPeriod() > 0)
        {
            clock_t time = clock();
            task->run();
            totalRunningTime +=
                    (clock() - time) /
                    (CLOCKS_PER_SEC * clockPerSecToMilliSec);
            --s_numberOfTasks;
        } else
            sleep(1);

    }

    return totalRunningTime;
}
