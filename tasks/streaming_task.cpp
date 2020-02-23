//
// Created by ali-masa on 2/22/20.
//

#include <iostream>
#include "streaming_task.h"

using namespace std;

StreamingTask::StreamingTask(Task &t, std::ostream& stream, string message)
:TaskDecorator(t), m_task(&t), m_streamer(&stream), m_message(message){}

void StreamingTask::run() {
    *m_streamer << this->m_message;
    this->m_task->run();
}

unsigned long StreamingTask::getNextRunPeriod() {
    return this->m_task->getNextRunPeriod();
}
