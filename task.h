//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_TASK_H
#define OS_SCHEDULER_TASK_H

struct Task
{
    friend class GreaterTask;
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() const = 0; // in milliseconds
};

struct GreaterTask{
    bool operator()(const Task* a,const Task* b) const{
        return a->getNextRunPeriod()>b->getNextRunPeriod();
    }
};

#endif //OS_SCHEDULER_TASK_H
