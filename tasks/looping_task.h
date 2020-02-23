//
// Created by ali-masa on 2/22/20.
//

#ifndef OS_SCHEDULER_LOOPING_TASK_H
#define OS_SCHEDULER_LOOPING_TASK_H

#include "task_decorator.h"

class LoopingTask: public TaskDecorator {
public:
    explicit LoopingTask(Task& t, unsigned int numOfLoops = 100);
    virtual void run();
    virtual unsigned long getNextRunPeriod();

private:
    Task* m_task;
    unsigned int m_numOfLoops;
};


#endif //OS_SCHEDULER_LOOPING_TASK_H
