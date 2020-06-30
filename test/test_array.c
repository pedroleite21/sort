#include "../tools/Unity/src/unity.h"
#include "../array.h"
#include <stdlib.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_RandomArray(void)
{
}

void test_AscendingArray(void)
{
    int size = 5;
    int *array = malloc(size*sizeof(int));
    int assert_array[6] = {0, 1, 2, 3, 4, 5};

    ascending_array(array, size);

    for (int i = 1; i <= size; i++)
    {
        TEST_ASSERT_EQUAL(assert_array[i], array[i]);
    }
}

void test_DescendingArray(void)
{
}

void test_AlmostOrderedArray(void)
{
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_AscendingArray);
    // RUN_TEST(test_AverageThreeBytes_should_AverageHighValues);
    return UNITY_END();
}