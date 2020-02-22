//
// Created by ali-masa on 2/22/20.
//

#include <iostream>
#include "printing_task.h"

using namespace std;

PrintingTask::PrintingTask(Task &t, std::ostream& stream, string message)
:TaskDecorator(t), m_task(&t), m_streamer(&stream), m_message(message){}

void PrintingTask::run() {
    *m_streamer << this->m_message;
    this->m_task->run();
}

unsigned long PrintingTask::getNextRunPeriod() {
    return this->m_task->getNextRunPeriod();
}

unsigned char PrintingTask::getPriority() {
    return this->m_task->getPriority();
}
