/*
 * Copyright (C) 2022, Linaro Ltd.
 * Author: Caleb Connolly <caleb.connolly@linaro.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CUTILS_LOCK_TRACKER_H__
#define __CUTILS_LOCK_TRACKER_H__

#include <pthread.h>

/* Uncomment to enable pthread mutex lock tracking */
//#define CUTILS_LOCK_TRACKER 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CUTILS_LOCK_TRACKER

#ifndef __FILENAME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

int _cthread_mutex_lock(pthread_mutex_t *m, const char *mtex, const char *file, const char *func,
			 int line);
int _cthread_mutex_unlock(pthread_mutex_t *m, const char *mtex, const char *file, const char *func,
			   int line);

int _cthread_cond_timedwait(pthread_cond_t *c, pthread_mutex_t *m, struct timespec *ts,
			     const char *mtex, const char *file, const char *func, int line);

int _cthread_cond_wait(pthread_cond_t *c, pthread_mutex_t *m, const char *mtex, const char *file,
			const char *func, int line);

void _cthread_dump_locks();

#define cthread_dump_locks()	 _cthread_dump_locks()

#define cthread_mutex_lock(m)	 _cthread_mutex_lock(m, #m, __FILENAME__, __FUNCTION__, __LINE__)

#define cthread_mutex_unlock(m) _cthread_mutex_unlock(m, #m, __FILENAME__, __FUNCTION__, __LINE__)

#define cthread_cond_timedwait(c, m, t)                                                           \
	_cthread_cond_timedwait(c, m, t, #m, __FILENAME__, __FUNCTION__, __LINE__)

#define cthread_cond_wait(c, m) _cthread_cond_wait(c, m, #m, __FILENAME__, __FUNCTION__, __LINE__)

#else

#define cthread_dump_locks()                                                                      \
	do {                                                                                       \
	} while (0)

#define cthread_mutex_lock(m)		 pthread_mutex_lock(m)

#define cthread_mutex_unlock(m)	 pthread_mutex_unlock(m)

#define cthread_cond_timedwait(c, m, t) pthread_cond_timedwait(c, m, t)

#define cthread_cond_wait(c, m)	 pthread_cond_wait(c, m)

#endif

#ifdef __cplusplus
}
#endif

#endif // __CUTILS_LOCK_TRACKER_H__
