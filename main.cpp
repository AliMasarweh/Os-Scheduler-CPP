#include <iostream>
#include <gtest/gtest.h>
#include <stdlib.h>
#include "time.h"

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