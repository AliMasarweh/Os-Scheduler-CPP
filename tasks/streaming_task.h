//
// Created by ali-masa on 2/22/20.
//

#ifndef OS_SCHEDULER_STREAMING_TASK_H
#define OS_SCHEDULER_STREAMING_TASK_H

#include <string>
#include "task_decorator.h"

class StreamingTask: public TaskDecorator {
public:
    explicit StreamingTask(Task& t, std::ostream& stream = std::cout, std::string message = "Running");
    virtual void run();
    virtual unsigned long getNextRunPeriod();

private:
    Task* m_task;
    std::string m_message;
    std::ostream* m_streamer;
};


#endif //OS_SCHEDULER_STREAMING_TASK_H
