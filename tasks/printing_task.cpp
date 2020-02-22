//
// Created by ali-masa on 2/22/20.
//

#include <iostream>
#include "printing_task.h"

using namespace std;

PrintingTask::PrintingTask(Task &t, string message)
:TaskDecorator(t), m_task(&t), m_message(message){}

void PrintingTask::run() {
    cout << this->m_message << endl;
    this->m_task->run();
}

unsigned long PrintingTask::getNextRunPeriod() {
    return this->m_task->getNextRunPeriod();
}

unsigned char PrintingTask::getPriority() {
    return this->m_task->getPriority();
}
