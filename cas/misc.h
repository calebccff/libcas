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

#ifndef __CUTILS_MISC_H__
#define __CUTILS_MISC_H__

#include <syscall.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#ifndef gettid
#define gettid() ((pid_t)syscall(SYS_gettid))
#endif

#ifndef zalloc
#define zalloc(size) calloc(1, (size))
#endif

struct enum_value {
	long long value;
	const char *name;
};

// TODO: named enum helper macros

#ifdef __cplusplus
}
#endif

#endif // __CUTILS_MISC_H__
