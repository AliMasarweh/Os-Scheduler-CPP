#include <iostream>
#include <gtest/gtest.h>
#include <stdlib.h>
#include "time.h"
#include "tasks/basic_task.h"
#include "tasks/streaming_task.h"
#include "tasks/looping_task.h"

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TimeUnitTesting, TimeAdditionAndSubstraction)
{
    unsigned long t1 = rand(),
            t2 = rand();
    Time time1(t1), time2(t2);

    ASSERT_EQ((time1+time2).getTime(), t1+t2);
    ASSERT_EQ((time1-time2).getTime(), t1-t2);
}


TEST(TimeUnitTesting, TimeRelationalOperatorTesting)
{
    unsigned long t1 = rand(),
            t2 = rand();
    Time time1(t1), time2(t2);

    ASSERT_EQ(time1<time2, t1<t2);
}

TEST(TaskUnitTesting, CreatingBasicTaskAndDecorating)
{
    stringstream ss;
    string str("I print");

    BasicTask task;
    StreamingTask streamingTask(task, ss, str);
    LoopingTask loopingTask(streamingTask, 3);

    loopingTask.run();

    ASSERT_EQ(ss.str(), str + str + str);
}

TEST(SchedulerUnitTesting, AllTasksExecution)
{
    //TODO: Add some tasks to the schudeler
    // Check if all are executed well
}

