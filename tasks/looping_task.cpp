//
// Created by ali-masa on 2/22/20.
//

#include "looping_task.h"

LoopingTask::LoopingTask(Task &t, unsigned int numOfLoops)
:TaskDecorator(t), m_task(&t), m_numOfLoops(numOfLoops){}

void LoopingTask::run() {
    for(unsigned int i = 0; i < m_numOfLoops; ++i)
        this->m_task->run();
}

unsigned long LoopingTask::getNextRunPeriod() {
    return this->m_task->getNextRunPeriod();
}

unsigned char LoopingTask::getPriority() {
    return this->m_task->getPriority();
}
