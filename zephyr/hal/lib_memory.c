/*
 *  lib_memory.c
 *
 *  Copyright 2014-2021 Michael Zillgith
 *
 *  This file is part of Platform Abstraction Layer (libpal)
 *  for libiec61850, libmms, and lib60870.
 */

#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "lib_memory.h"

LOG_MODULE_REGISTER(iec61850, CONFIG_IEC61850_LOG_LEVEL);

static MemoryExceptionHandler exceptionHandler = NULL;
static void* exceptionHandlerParameter = NULL;

K_HEAP_DEFINE(iec61850_heap, CONFIG_IEC61850_HEAP_SIZE);

static void
noMemoryAvailableHandler(void)
{
    LOG_ERR("Failed to allocate memory!");
    
    if (exceptionHandler != NULL)
        exceptionHandler(exceptionHandlerParameter);
}

void
Memory_installExceptionHandler(MemoryExceptionHandler handler, void* parameter)
{
    exceptionHandler = handler;
    exceptionHandlerParameter = parameter;
}

void*
Memory_malloc(size_t size)
{
    //void* memory = malloc(size);
    void* memory = k_heap_alloc(&iec61850_heap, size, K_MSEC(100));

    if (memory == NULL)
        noMemoryAvailableHandler();

    return memory;
}

void*
Memory_calloc(size_t nmemb, size_t size)
{
    //void* memory = calloc(nmemb, size);
    void* memory = k_heap_calloc(&iec61850_heap, nmemb, size, K_MSEC(100));

    if (memory == NULL)
        noMemoryAvailableHandler();

    return memory;
}

void *
Memory_realloc(void *ptr, size_t size)
{
    //void* memory = realloc(ptr, size);
    void* memory = k_heap_realloc(&iec61850_heap, ptr, size, K_MSEC(100));

    if (memory == NULL)
        noMemoryAvailableHandler();

    return memory;
}

void
Memory_free(void* memb)
{
    //free(memb);
    k_heap_free(&iec61850_heap, memb);
}

