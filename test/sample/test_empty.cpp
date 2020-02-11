#include <unity.h>

void setUp()
{
}

void tearDown()
{
}

void testSample()
{
  TEST_ASSERT_EQUAL(true /* reference */, true /* real value */);
}

int main(int argc, char** argv)
{
  UNITY_BEGIN();

  RUN_TEST(testSample);

  UNITY_END();
}
