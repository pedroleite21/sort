#include "../tools/Unity/src/unity.h"
#include "../sort.h"
#include "../array.h"
#include <stdlib.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_SortingMethods(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // quicksort
    quick_sort(array, 5, 5);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_SortingMethods);
    return UNITY_END();
}
