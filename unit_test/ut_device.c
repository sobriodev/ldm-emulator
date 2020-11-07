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
    DEVICE_Destroy(&device);
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

void UT_DEVICE_ErrStatusWhenNullPtrsGiven(void)
{
    /*** Setup ***/
    SetUp();

    /*** When ***/
    DEVICE_Status nullDevAlloc = DEVICE_CreateWithAllocator(NULL, 0, malloc);

    DEVICE_Handle* device;
    DEVICE_Status nullAllocatorAlloc = DEVICE_CreateWithAllocator(&device, 0, NULL);

    DEVICE_Status nullDevDestroy = DEVICE_Destroy(NULL);

    /*** Then ***/
    UT_STATUS_EQ(DEVICE_StatusNullPtr, nullDevAlloc);
    UT_STATUS_EQ(DEVICE_StatusNullPtr, nullAllocatorAlloc);
    UT_STATUS_EQ(DEVICE_StatusNullPtr, nullDevDestroy);

    /*** Teardown ***/
    TearDown();
}

void UT_DEVICE_Destroy_HandleIsSetToNull(void)
{
    /*** Setup ***/
    SetUp();

    /*** When ***/
    DEVICE_Handle* device;
    DEVICE_Create(&device, 0);
    DEVICE_Status status = DEVICE_Destroy(&device);

    /*** Then ***/
    UT_STATUS_EQ(DEVICE_StatusOk, status);
    TEST_ASSERT_EQUAL_PTR(DEVICE_UNDEFINED, device);

    /*** Teardown ***/
    DEVICE_Destroy(&device);
    TearDown();
}
