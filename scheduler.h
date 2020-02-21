//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_SCHEDULER_H
#define OS_SCHEDULER_SCHEDULER_H

#include <vector>

class Task;

class Scheduler {
public:
    static unsigned long currentTime();
    static void addTask(Task& t);
    static Time runAllTasks();

private:
    static unsigned long s_time;
    /* This a collections indexes tasks by their priority */
    static std::vector<std::vector<Task*> > s_tasksByPriority;
};

#endif //OS_SCHEDULER_SCHEDULER_H
