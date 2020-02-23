//
// Created by ali-masa on 2/22/20.
//

#include "basic_task.h"
#include "../scheduler.h"

void BasicTask::run() {
    if(m_repetition--)
        m_executionTime += m_executionTimeFreq;
    else
        m_executionTime = -1;
}

unsigned long BasicTask::getNextRunPeriod() const {
    unsigned long time = Scheduler::currentTime().getTime();
    if(m_executionTime > time)
        return (m_executionTime - time).getTime();

    return 0;
}

BasicTask::BasicTask(unsigned long waitingTime, unsigned long execTimeFreq,
        unsigned char repetition)
:m_executionTime(Scheduler::currentTime() + waitingTime),
 m_executionTimeFreq(execTimeFreq),
 m_repetition(repetition){}
