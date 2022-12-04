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

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h> // for memset

#include <cas/bytearray.h>
#include <cas/misc.h>

struct bytearray *ba_init(size_t size)
{
	struct bytearray *arr = zalloc(sizeof(struct bytearray));
	arr->len = size;
	arr->data = zalloc(4096);
	//log_info("Created array of %zu bytes", arr->len);

	return arr;
}

void ba_free(struct bytearray *ba)
{
	free(ba->data);
	free(ba);
}

void ba_set_size(struct bytearray *ba, size_t newsize)
{
	ba->data = realloc(ba->data, newsize);
	memset(ba->data + ba->len, 0, newsize - ba->len);
	ba->len = newsize;
}