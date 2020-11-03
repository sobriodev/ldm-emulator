#include "ut.h"
#include "unity.h"

#include <stdio.h>

int main(void)
{
    UNITY_BEGIN();
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
