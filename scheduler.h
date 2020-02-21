//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_SCHEDULER_H
#define OS_SCHEDULER_SCHEDULER_H

#include <vector>
#include "time.h"

class Task;

class Scheduler {
public:
    static const Time& currentTime();
    static void addTask(Task& t);
    static Time runAllTasks();

private:
    static std::vector<std::vector<Task *> > initTasksContainer();

    static Time s_time;
    /* This a collections indexes tasks by their priority */
    const static unsigned char s_highestPriority = 10;
    static std::vector<std::vector<Task*> > s_tasksByPriority;
};

#endif //OS_SCHEDULER_SCHEDULER_H
