//
// Created by ali-masa on 2/22/20.
//

#ifndef OS_SCHEDULER_TASK_DECORATOR_H
#define OS_SCHEDULER_TASK_DECORATOR_H

#include "../task.h"

class TaskDecorator: public Task
{
    Task* task;
public:
    explicit TaskDecorator(Task& t);
    virtual void run();
    virtual unsigned long getNextRunPeriod();
    virtual unsigned char getPriority();
};

#endif //OS_SCHEDULER_TASK_DECORATOR_H
