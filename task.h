//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_TASK_H
#define OS_SCHEDULER_TASK_H

struct Task
{
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
    virtual unsigned char getPriority() = 0;
};

#endif //OS_SCHEDULER_TASK_H
