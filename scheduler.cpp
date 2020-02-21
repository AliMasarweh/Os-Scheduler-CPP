//
// Created by ali-masa on 2/21/20.
//

#include "scheduler.h"

std::vector<std::vector<Task*> >
        Scheduler::s_tasksByPriority = Scheduler::initTasksContainer();

const Time& Scheduler::currentTime() {
    return s_time;
}

void Scheduler::addTask(Task &t) {
    s_tasksByPriority[t.getPrioirty()].push_back(&t);
}

Time Scheduler::runAllTasks() {
    Time totalRunningTime(0);

    return totalRunningTime;
}

std::vector<std::vector<Task *> > Scheduler::initTasksContainer() {
    std::vector<std::vector<Task *> > ans(s_highestPriority);

    for(unsigned char i = 0; i < s_highestPriority; ++i)
    {
        ans.push_back(std::vector<Task *>());
    }

    return ans;
}

