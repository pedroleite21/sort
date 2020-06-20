
#include "foo.h"
#include "unity.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_foo1(void)
{
  /* All of these should pass */
  TEST_ASSERT_EQUAL(-2, foo(1,2));
  TEST_ASSERT_EQUAL(-1, foo(2,2));
}

void test_foo2(void)
{
  TEST_ASSERT_EQUAL(2, foo(1,2)); // vai dar erro !!!!
}
