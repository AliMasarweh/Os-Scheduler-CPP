//
// Created by ali-masa on 2/22/20.
//

#ifndef OS_SCHEDULER_BASIC_TASK_H
#define OS_SCHEDULER_BASIC_TASK_H

#include "../task.h"
#include "../time.h"

class BasicTask: public Task {
public:
    BasicTask(unsigned long waitingTime = 0, unsigned long execTimeFreq = 0,
            unsigned char repetition = 1);
    virtual void run();
    virtual unsigned long getNextRunPeriod() const;

private:
    Time m_executionTime;
    Time m_executionTimeFreq;
    unsigned char m_repetition;
};


#endif //OS_SCHEDULER_BASIC_TASK_H
