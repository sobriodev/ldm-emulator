#include "ut.h"
#include "unity.h"

#include <stdio.h>

int main(void)
{
    UNITY_BEGIN();

	/* UT_DEVICE */
	RUN_TEST(UT_DEVICE_GetNext_ByDefaultReturnsUndefinedDevice);
	RUN_TEST(UT_DEVICE_CreateWithAllocator_ErrStatusWhenAllocatorFails);
	RUN_TEST(UT_DEVICE_CreateWithAllocator_ErrStatusWhenNullPtrsGiven);

    return UNITY_END();
}

void setUp()
{
    /* There must be a setUp() definiton altough it is not used by the unit test module */
}
void tearDown()
{
    /* There must be a tearDown() definiton altough it is not used by the unit test module */
}
