//
// Created by ali-masa on 2/22/20.
//

#ifndef OS_SCHEDULER_BASIC_TASK_H
#define OS_SCHEDULER_BASIC_TASK_H

#include "../task.h"
#include "../time.h"

class BasicTask: public Task {
public:
    BasicTask(unsigned char priority = 1, unsigned long waitingTime = 0);
    virtual void run();
    virtual unsigned long getNextRunPeriod();
    virtual unsigned char getPriority();

private:
    Time m_runningTime;
    unsigned char m_priority;
    Time m_executionTime;
};


#endif //OS_SCHEDULER_BASIC_TASK_H
