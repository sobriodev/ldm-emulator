#include "ut.h"
#include "device.h"

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------------- Private functions -------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* Setup and teardown functions to perform common initialization and destruction */
static void SetUp(void) {}
static void TearDown(void) {}

/* Stub function to check API behaviour when memory allocation failure occurs */
static void* MemAllocatorStub(size len)
{
    (void)len;
    return NULL;
}

/* ---------------------------------------------------------------------------------------------- */
/* ---------------------------------------- Test cases  ----------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

void UT_DEVICE_GetNext_ByDefaultReturnsUndefinedDevice(void)
{
    /*** Setup ***/
    SetUp();

    /*** When ***/
    DEVICE_Handle* device;
    DEVICE_Status status = DEVICE_Create(&device, 0);

    /*** Then ***/
    TEST_ASSERT_EQUAL_PTR(DEVICE_UNDEFINED, DEVICE_GetNext(device));
    UT_STATUS_EQ(DEVICE_StatusOk, status);

    /*** Teardown ***/
    TearDown();
}

void UT_DEVICE_CreateWithAllocator_ErrStatusWhenAllocatorFails(void)
{
    /*** Setup ***/
    SetUp();

    /*** When ***/
    DEVICE_Handle* device;
    DEVICE_Status status = DEVICE_CreateWithAllocator(&device, 0, MemAllocatorStub);

    /*** Then ***/
    UT_STATUS_EQ(DEVICE_StatusMemErr, status);

    /*** Teardown ***/
    TearDown();
}

void UT_DEVICE_CreateWithAllocator_ErrStatusWhenNullPtrsGiven(void)
{
    /*** Setup ***/
    SetUp();

    /*** When ***/
    DEVICE_Status nullDevStatus = DEVICE_CreateWithAllocator(NULL, 0, malloc);
    DEVICE_Handle* device;
    DEVICE_Status nullAllocatorStatus = DEVICE_CreateWithAllocator(&device, 0, NULL);

    /*** Then ***/
    UT_STATUS_EQ(DEVICE_StatusNullPtr, nullDevStatus);
    UT_STATUS_EQ(DEVICE_StatusNullPtr, nullAllocatorStatus);

    /*** Teardown ***/
    TearDown();
}
