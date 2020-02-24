//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_SCHEDULER_H
#define OS_SCHEDULER_SCHEDULER_H

#include <vector>
#include <queue>
#include "time.h"

class Task;

class Scheduler {
public:
    static const Time& currentTime();
    static void addTask(Task& t);
    static Time runAllTasks();

private:
    static std::vector<Task*> s_prioritizedTasks;
    static Time s_time;
    static size_t s_numberOfTasks;
};

#endif //OS_SCHEDULER_SCHEDULER_H
