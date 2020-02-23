//
// Created by ali-masa on 2/22/20.
//

#include "task_decorator.h"

TaskDecorator::TaskDecorator(Task &t) {
    this->task = &t;
}

void TaskDecorator::run() {
    this->task->run();
}

unsigned long TaskDecorator::getNextRunPeriod() {
    return this->task->getNextRunPeriod();
}
