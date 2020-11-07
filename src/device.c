#include "device.h"

#include <stdio.h>

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

DEVICE_Status DEVICE_Destroy(DEVICE_Handle** device)
{
    COMMON_DIE_IF_NULL(device, DEVICE_StatusNullPtr);

    free(*device);
    *device = DEVICE_UNDEFINED;
    return DEVICE_StatusOk;
}

void DEVICE_PrintChain(const DEVICE_Handle* device)
{
    if (DEVICE_UNDEFINED == device) {
        printf("UNDEFINED DEVICE\n");
    } else {
        printf("DEVICE@%p {id: %u, next: %p} ->\n", device, device->id, device->next);
        DEVICE_PrintChain(device->next);
    }
}
