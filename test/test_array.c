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
    // TEST TO FAIL
    int size = 5;
    int *array = malloc(size*sizeof(int));
    int assert_array[6] = {5, 4, 3, 2, 1};

    random_array(array, size);

    for (int i = 1; i <= size; i++)
    {

        TEST_ASSERT_EQUAL(assert_array[i], array[i]);
    }
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
    int size = 5;
    int *array = malloc(size*sizeof(int));
    int assert_array[6] = {5, 4, 3, 2, 1};

    descending_array(array, size);

    for (int i = 1; i <= size; i++)
    {

        TEST_ASSERT_EQUAL(assert_array[i], array[i]);
    }
}

void test_AlmostOrderedArray(void)
{
    // TEST TO FAIL
    int size = 5;
    int *array = malloc(size*sizeof(int));
    int assert_array[6] = {5, 4, 3, 2, 1};

    almost_ordered_array(array, size);

    for (int i = 1; i <= size; i++)
    {

        TEST_ASSERT_EQUAL(assert_array[i], array[i]);
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_AscendingArray);
    RUN_TEST(test_DescendingArray);
    RUN_TEST(test_AlmostOrderedArray);
    RUN_TEST(test_RandomArray);
    return UNITY_END();
}