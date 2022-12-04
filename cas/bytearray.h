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

#ifndef __CUTILS_BYTEARRAY_H__
#define __CUTILS_BYTEARRAY_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct bytearray {
	size_t len;
	void* data;
};

struct bytearray *ba_init(size_t size);
void ba_set_size(struct bytearray *ba, size_t newsize);
void ba_free(struct bytearray *ba);

#ifdef __cplusplus
}
#endif

#endif // __CUTILS_BYTEARRAY_H__
