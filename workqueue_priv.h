#ifndef __CUTILS_WORKQUEUE_PRIV_H__
#define __CUTILS_WORKQUEUE_PRIV_H__

#include <stdbool.h>
#include <unistd.h>
#include "workqueue.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief: Set up the workqueue, must be called once
 * before work items can be queued
 */
void c_workqueue_init();

void c_workqueue_dump();

int c_threads_exitall();

#ifdef __cplusplus
}
#endif

#endif // __CUTILS_WORKQUEUE_PRIV_H__
