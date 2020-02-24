#include <iostream>
#include <gtest/gtest.h>
#include <stdlib.h>
#include <queue>
#include "time.h"
#include "tasks/basic_task.h"
#include "tasks/streaming_task.h"
#include "tasks/looping_task.h"
#include "tasks/sleeping_task.h"

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
    SleepingTask sleepingTask(streamingTask, 1);
    LoopingTask loopingTask(sleepingTask, 3);

    loopingTask.run();

    ASSERT_EQ(ss.str(), str + str + str);
}

TEST(TaskUnitTesting, BasicTaskComparision)
{
    BasicTask task1(1);
    BasicTask task2(3);

    ASSERT_TRUE(task2.getNextRunPeriod()
        > task1.getNextRunPeriod());

    BasicTask* pTask2 = &task2;
    BasicTask* pTask1 = &task1;

    ASSERT_TRUE(GreaterTask()(pTask2, pTask1));

    size_t add_pTask1 = (size_t) pTask1;
    size_t add_pTask2 = (size_t) pTask2;
    ASSERT_TRUE(add_pTask1 < add_pTask2);
}

TEST(GreaterTaskUnitTesting, OrderingTest)
{
    priority_queue<Task*, vector<Task*>, GreaterTask> tasks;

    int arr[] = {43,23,63,45,42,12,32,34,2};

    size_t n = sizeof(arr)/sizeof(int);

    Task* arrTasks[n];

    for(int i = 0; i < n; ++i)
    {
        arrTasks[i] = new BasicTask(arr[i]);
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; ++i)
    {
        tasks.push(arrTasks[i]);
    }

    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " " << tasks.top()->getNextRunPeriod() << endl;
        tasks.pop();
//        ASSERT_EQ(arr[i], tasks[i]->getNextRunPeriod());
    }

    for(int i = 0; i < n; ++i)
    {
        delete arrTasks[i];
    }
}

TEST(SchedulerUnitTesting, AllTasksExecution)
{
    //TODO: Add some tasks to the schudeler
    // Check if all are executed well
}

