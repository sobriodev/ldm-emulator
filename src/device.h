#ifndef DEVICE_H
#define DEVICE_H

#include "common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------------------ Macros -------------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/**< Used to represent an undefined device */
#define DEVICE_UNDEFINED ((DEVICE_Handle*)NULL)

/* ---------------------------------------------------------------------------------------------- */
/* ---------------------------------------- Data types ------------------------------------------ */
/* ---------------------------------------------------------------------------------------------- */

/** An enum to represent status codes */
typedef enum
{
    DEVICE_StatusOk,      /**< OK */
    DEVICE_StatusNullPtr, /**< Valid pointer expected */
    DEVICE_StatusMemErr,  /**< Memory allocation error */
} DEVICE_Status;

/** Device properties */
typedef struct DEVICE_Handle
{
    u32 id;                     /**< Device identifier */
    struct DEVICE_Handle* next; /**< Pointer to next device */
} DEVICE_Handle;

/** Memory allocator function type */
typedef void* (*DEVICE_MemAllocator)(size len);

/* ---------------------------------------------------------------------------------------------- */
/* --------------------------------------- Api functions ---------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief Create device with a custom memory allocator.
 *
 * The function allocates device memory and initializes it with specified values.
 *
 * @param device Pointer that will point to allocated resources
 * @param id     Device ID. Must be unique within an application
 * @param alloc  Custom memory allocator
 *
 * @return Instance of DEVICE_Status. The function returns:
 *          - DEVICE_StatusNullPtr when NULL was passed instead of valid pointer
 *          - DEVICE_StatusMemErr when memory allocator fails
 *          - DEVICE_StatusOk on success
 *
 * @see DEVICE_Create to create device with a default memory allocator.
 * @see DEVICE_MemAllocator to get a valid memory allocator type.
 */
DEVICE_Status DEVICE_CreateWithAllocator(DEVICE_Handle** device, u32 id, DEVICE_MemAllocator alloc);

/**
 * @brief Create device with a default memory allocator.
 *
 * The function is a helper only and calls DEVICE_CreateWithAllocator internally.
 *
 * @param device Pointer that will point to allocated resources
 * @param id     Device ID. Must be unique within an application
 *
 * @return Instance of DEVICE_status. See DEVICE_CreateWithAllocator to get status codes that
 *         function returns
 */
static inline DEVICE_Status DEVICE_Create(DEVICE_Handle** device, u32 id)
{
    return DEVICE_CreateWithAllocator(device, id, malloc);
}

/**
 * @brief Get next (child) device.
 *
 * Get address of next device in the chain.
 *
 * @param device Parent device
 *
 * @return Pointer to a next device or DEVICE_UNDEFINED if device does not have a child.
 */
static inline DEVICE_Handle* DEVICE_GetNext(const DEVICE_Handle* device)
{
    return device->next;
}

#if defined(__cplusplus)
}
#endif

#endif // DEVICE_H
