//
// Created by ali-masa on 2/24/20.
//

#ifndef OS_SCHEDULER_SLEEPING_TASK_H
#define OS_SCHEDULER_SLEEPING_TASK_H


#include "task_decorator.h"
#include "../time.h"

class SleepingTask: public TaskDecorator {
public:
    explicit SleepingTask(Task& t, Time time);
    virtual void run();
    virtual unsigned long getNextRunPeriod() const;

private:
    Task* m_task;
    Time m_time;
};


#endif //OS_SCHEDULER_SLEEPING_TASK_H
