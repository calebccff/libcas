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

#ifndef __CUTILS_H__
#define __CUTILS_H__

#include <stdint.h>


#include "config.h"
#include <cas/timespec.h>
#include <cas/bytearray.h>
#include <cas/log.h>
#include <cas/misc.h>
#include <workqueue.h>

char to_hex(uint8_t ch);
void print_hex_dump(const char *prefix, const void *buf, size_t len);

int msleep(long ms);

#endif // __CUTILS_H__
