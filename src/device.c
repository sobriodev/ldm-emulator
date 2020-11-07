#include "device.h"

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------------- Private functions -------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

static void SetProperties(DEVICE_Handle* dev, u32 id)
{
    dev->id = id;
    /* By default device points to and undefined child device */
    dev->next = DEVICE_UNDEFINED;
}

/* ---------------------------------------------------------------------------------------------- */
/* --------------------------------------- Api functions ---------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

DEVICE_Status DEVICE_CreateWithAllocator(DEVICE_Handle** device, u32 id, DEVICE_MemAllocator alloc)
{
    COMMON_DIE_IF_NULL(device, DEVICE_StatusNullPtr);
    COMMON_DIE_IF_NULL(alloc, DEVICE_StatusNullPtr);

    *device = alloc(sizeof(DEVICE_Handle));
    COMMON_DIE_IF_NULL(*device, DEVICE_StatusMemErr);

    SetProperties(*device, id);
    return DEVICE_StatusOk;
}
