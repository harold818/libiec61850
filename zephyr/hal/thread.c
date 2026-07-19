/*
 *  thread_linux.c
 *
 *  Copyright 2013-2021 Michael Zillgith
 *
 *  This file is part of Platform Abstraction Layer (libpal)
 *  for libiec61850, libmms, and lib60870.
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "hal_thread.h"
#include "lib_memory.h"

LOG_MODULE_DECLARE(iec61850);

/* CONFIG_MMS_SINGLE_THREADED
 * 1 ==> server runs in single threaded mode (one dedicated thread for the server)
 * 0 ==> server runs in multi threaded mode (one thread for each connection and
 * one server background thread )
 */

#define IEC61850_THREAD_COUNT   6 //COND_CODE_1(IS_ENABLED(CONFIG_MMS_SINGLE_THREADED), (1), (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS + 1)) 

struct sThread {
    bool active;
    ThreadExecutionFunction function;
    void* parameter;
    k_tid_t thread_id;
    struct k_thread thread;
    bool autodestroy;
};

K_MUTEX_DEFINE(iec61850_thread_mutex);
K_THREAD_STACK_ARRAY_DEFINE(iec61850_stacks, IEC61850_THREAD_COUNT, CONFIG_MMS_STACK_SIZE);
static struct sThread iec61850_threads[IEC61850_THREAD_COUNT];

Semaphore
Semaphore_create(int initialValue)
{
    Semaphore self = GLOBAL_MALLOC(sizeof(struct k_sem));

    k_sem_init((struct k_sem*) self, initialValue, 1);

    return self;
}

/* Wait until semaphore value is more than zero. Then decrease the semaphore value. */
void
Semaphore_wait(Semaphore self)
{
    k_sem_take((struct k_sem*) self, K_FOREVER);
}

void
Semaphore_post(Semaphore self)
{
    k_sem_give((struct k_sem*) self);
}

void
Semaphore_destroy(Semaphore self)
{
    k_sem_reset((struct k_sem*) self);
    GLOBAL_FREEMEM(self);
}

Thread
Thread_create(ThreadExecutionFunction function, void* parameter, bool autodestroy)
{
    Thread thread = NULL;

    k_mutex_lock(&iec61850_thread_mutex, K_FOREVER);

    int i;
    for(i = 0; i < IEC61850_THREAD_COUNT; i++) {
        thread = &iec61850_threads[i];
        if(!thread->active){
            thread->active = true;
            thread->parameter = parameter;
            thread->function = function;
            thread->thread_id = NULL;
            thread->autodestroy = autodestroy;
            break;
        }
    }
    if(i == IEC61850_THREAD_COUNT){
        thread = NULL;
    }

    if(!thread){
        LOG_ERR("Failed to allocate thread");
    }
    else{
        LOG_INF("Created thread at index %d", i);
    }

    k_mutex_unlock(&iec61850_thread_mutex);

    return thread;
}

static void
destroyAutomaticThread(void* parameter, void* parameter2, void* parameter3)
{
    Thread thread = (Thread) parameter;
    k_tid_t tid = thread->thread_id;

    thread->function(thread->parameter);

    k_mutex_lock(&iec61850_thread_mutex, K_FOREVER);
    memset(thread, 0, sizeof(struct sThread));
    k_mutex_unlock(&iec61850_thread_mutex);

    k_thread_abort(tid);
}

static void
threadRunner(void* parameter, void* parameter2, void* parameter3)
{
    Thread thread = (Thread) parameter;
    
    thread->function(thread->parameter);
}

void
Thread_start(Thread thread)
{
    k_thread_entry_t function = NULL;

    int index = ARRAY_INDEX(iec61850_threads, thread);

    LOG_INF("Starting thread %d", index);

    if (thread->autodestroy == true) {
        function = destroyAutomaticThread;
    }
    else {
        function = threadRunner;
    }
        
    thread->thread_id = k_thread_create(
        &thread->thread, 
        iec61850_stacks[index], 
        CONFIG_MMS_STACK_SIZE,
        function, 
        thread,
        NULL,
        NULL,
        CONFIG_MMS_THREAD_PRIORITY,
        0,
        K_NO_WAIT
    );    
}

void
Thread_destroy(Thread thread)
{
    k_mutex_lock(&iec61850_thread_mutex, K_FOREVER);
    if(thread->active) {
        k_thread_abort(thread->thread_id);
        memset(thread, 0, sizeof(struct sThread));
    }
    k_mutex_unlock(&iec61850_thread_mutex);
}

void
Thread_sleep(int millies)
{
    k_msleep(millies);
}

