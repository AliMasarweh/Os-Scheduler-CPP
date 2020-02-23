//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_TASK_H
#define OS_SCHEDULER_TASK_H

struct Task
{
    friend bool operator>(const Task& t1, const Task& t2)
    {
        return t1.getNextRunPeriod() > t2.getNextRunPeriod();
    }
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() const = 0; // in milliseconds
};

#endif //OS_SCHEDULER_TASK_H
