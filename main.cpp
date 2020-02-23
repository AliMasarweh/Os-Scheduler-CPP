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

TEST(TaskUnitTesting, BasicTaskComparision)
{
    BasicTask task1(1);
    BasicTask task2(3);

    ASSERT_TRUE(task2 > task1);

    BasicTask* pTask2 = &task2;
    BasicTask* pTask1 = &task1;
    cout << (pTask2 > pTask1) << endl;
    ASSERT_TRUE(pTask2 > pTask1);

    size_t add_pTask1 = (size_t) pTask1;
    size_t add_pTask2 = (size_t) pTask2;
    ASSERT_TRUE(add_pTask1 < add_pTask2);
}

TEST(SchedulerUnitTesting, AllTasksExecution)
{
    //TODO: Add some tasks to the schudeler
    // Check if all are executed well
}

