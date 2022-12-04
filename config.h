
#ifndef __LIBCAS_CONFIG_H__
#define __LIBCAS_CONFIG_H__

/*
 * Copy this file to your project and include it before including
 * <cas/cutils.h>.
 */

/**
 * Number of workqueue threads to create.
 * Only relevant if using c_workqueue_*()
 * libcas must be recompiled to change this
*/
#define C_WORK_N_THREADS 6

/**
 * Enable runtime lock tracking, requires that
 * your project use the cthread_* wrappers instead
 * of calling pthread_* directly. When enabled
 * call cthread_dump_locks() to dump a list of all
 * locks and their states. Hook this up to SIGHUP to
 * trigger it from a deadlock situation.
 * 
 * TODO: automatically register sighup listener
*/
#define CUTILS_LOCK_TRACKER

#ifdef CUTILS_LOCK_TRACKER
#undef CUTILS_LOCK_TRACKER
#endif

#endif // __LIBCAS_CONFIG_H__
