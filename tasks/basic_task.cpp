//
// Created by ali-masa on 2/22/20.
//

#include "basic_task.h"
#include "../scheduler.h"

void BasicTask::run() {
    // Open the stack
}

unsigned long BasicTask::getNextRunPeriod() {
    unsigned long time = Scheduler::currentTime().getTime();
    if(m_executionTime > time)
        return (m_executionTime - time).getTime();

    return 0;
}

unsigned char BasicTask::getPriority() {
    return this->m_priority;
}

BasicTask::BasicTask(unsigned char priority, unsigned long waitingTime)
:m_priority(priority),
m_executionTime(Scheduler::currentTime() + waitingTime) {}
