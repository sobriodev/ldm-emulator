#ifndef UT_H
#define UT_H

#include "unity.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------------------- MACROS ------------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

#define UT_STATUS_EQ(EXP, ACT) TEST_ASSERT_EQUAL_UINT32((EXP), (ACT))

/* ---------------------------------------------------------------------------------------------- */
/* -------------------------------------- Test declarations ------------------------------------- */
/* ---------------------- Naming convention: UT_{MODULE}_{FUNCTION}_{CONDITION} ----------------- */
/* ---------------------------------------------------------------------------------------------- */

/* Put tests declaration here */

/* UT_DEVICE */
void UT_DEVICE_GetNext_ByDefaultReturnsUndefinedDevice(void);
void UT_DEVICE_CreateWithAllocator_ErrStatusWhenAllocatorFails(void);
void UT_DEVICE_ErrStatusWhenNullPtrsGiven(void);
void UT_DEVICE_Destroy_HandleIsSetToNull(void);

/* End of the tests declaration */

#if defined(__cplusplus)
}
#endif

#endif // UT_H
