#include "../tools/Unity/src/unity.h"
#include "../array.h"
#include "../get_opt.h"
#include "../sort.h"
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

void test_ReturnSortingName(void)
{
    TEST_ASSERT_EQUAL(0, get_sort_method("selection"));
    TEST_ASSERT_EQUAL(1, get_sort_method("insertion"));
    TEST_ASSERT_EQUAL(2, get_sort_method("shell"));
    TEST_ASSERT_EQUAL(3, get_sort_method("quick"));
    TEST_ASSERT_EQUAL(4, get_sort_method("heap"));
    TEST_ASSERT_EQUAL(-1, get_sort_method("wrongname"));
}

void test_ReturnArraySizeFromString(void)
{
    TEST_ASSERT_EQUAL(10, get_array_size("10"));
    TEST_ASSERT_EQUAL(-1, get_array_size("-10"));
}

void test_ReturnArrayTypeFromString(void)
{
    TEST_ASSERT_EQUAL(0, get_array_type("random"));
    TEST_ASSERT_EQUAL(1, get_array_type("ascending"));
    TEST_ASSERT_EQUAL(2, get_array_type("descending"));
    TEST_ASSERT_EQUAL(3, get_array_type("almost"));
    TEST_ASSERT_EQUAL(-1, get_array_type("wrongname"));
}

void test_SelectionSort(void)
{
    int expected_array[6] = {8, 40, 50, 90, 100, 279};
    int actual_array[6] = {100, 8, 40, 279, 90, 50};
    selection_sort((int *)actual_array, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, actual_array, 6);
}

void test_InserionSort(void)
{
    int expected_array[6] = {8, 40, 50, 90, 100, 279};
    int actual_array[6] = {100, 8, 40, 279, 90, 50};
    insertion_sort((int *)actual_array, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, actual_array, 6);
}

void test_ShellSort(void)
{
    int expected_array[6] = {8, 40, 50, 90, 100, 279};
    int actual_array[6] = {100, 8, 40, 279, 90, 50};
    shell_sort((int *)actual_array, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, actual_array, 6);
}

void test_MergeSort(void)
{
    int expected_array[6] = {8, 40, 50, 90, 100, 279};
    int actual_array[6] = {100, 8, 40, 279, 90, 50};
    merge_sort((int *)actual_array, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, actual_array, 6);
}

void test_HeapSort(void)
{
    int expected_array[6] = {8, 40, 50, 90, 100, 279};
    int actual_array[6] = {100, 8, 40, 279, 90, 50};
    heap_sort(actual_array, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, actual_array, 6);
}

void test_QuickSort(void)
{
    int expected_array[6] = {8, 40, 50, 90, 100, 279};
    int actual_array[6] = {100, 8, 40, 279, 90, 50};
    quick_sort(actual_array, 0, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, actual_array, 6);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_AscendingArray);
    RUN_TEST(test_DescendingArray);
    RUN_TEST(test_AlmostOrderedArray);
    RUN_TEST(test_RandomArray);
    RUN_TEST(test_ReturnSortingName);
    RUN_TEST(test_ReturnArraySizeFromString);
    RUN_TEST(test_ReturnArrayTypeFromString);
    RUN_TEST(test_SelectionSort);
    RUN_TEST(test_InserionSort);
    RUN_TEST(test_ShellSort);
    RUN_TEST(test_MergeSort);
    RUN_TEST(test_HeapSort);
    RUN_TEST(test_QuickSort);
    return UNITY_END();
}