//
// Created by ali-masa on 2/24/20.
//

#include <unistd.h>
#include "sleeping_task.h"

SleepingTask::SleepingTask(Task &t, Time time): TaskDecorator(t),
 m_task(&t), m_time(time) {}

void SleepingTask::run() {
    this->m_task->run();
    sleep(this->m_time.getTime());
}

unsigned long SleepingTask::getNextRunPeriod() const {
    return this->m_task->getNextRunPeriod();
}
