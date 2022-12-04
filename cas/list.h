/*
 * Copyright (c) 2016, Linaro Ltd.
 * From: https://github.com/andersson/qmic/blob/master/list.h
 * Contributions by Caleb Connolly <caleb.connolly@linaro.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CUTILS_LIST_H__
#define __CUTILS_LIST_H__

#include <pthread.h>
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef offsetof
#define offsetof(type, md) ((unsigned long)&((type *)0)->md)
#endif

#ifndef container_of
#define container_of(ptr, type, member)                                        \
	((type *)((char *)(ptr)-offsetof(type, member)))
#endif

// The list has a head and a tail, each list item
// has a previous and next item
struct list_head {
	union {
		struct list_head *next;
		struct list_head *head;
	};
	union {
		struct list_head *prev;
		struct list_head *tail;
	};
};

static inline void list_init(struct list_head *list)
{
	list->head = list->tail = list;
}

#define LIST_INIT(l) { &(l), &(l) }

static inline void list_append(struct list_head *list, struct list_head *item)
{
	struct list_head *tail = list->tail;

	item->next = list;
	item->prev = tail;

	tail->next = list->prev = item;
}

static inline void list_prepend(struct list_head *list, struct list_head *item)
{
	struct list_head *head = list->head;

	list->head = item;

	item->next = head;
	item->prev = list;

	head->prev = list->next = item;
}

static inline void list_remove(struct list_head *item)
{
	item->prev->next = item->next;
	item->next->prev = item->prev;
}

static inline struct list_head *list_pop(struct list_head *list)
{
	struct list_head *item;
	item = list->head;
	if (item == 0)
		return 0;
	list_remove(item);
	return item;
}

static inline struct list_head *list_last(struct list_head *list)
{
	return list->tail;
}

static inline struct list_head *list_first(struct list_head *list)
{
	return list->head;
}

static inline struct list_head *list_next(struct list_head *item)
{
	return item->next;
}

#define list_push list_append

#define list_empty(li) ((li)->next == (li))

#define list_for_each(_list, _iter)                                            \
	for (_iter = (_list)->head; (_iter) != (_list); _iter = (_iter)->next)

#define list_for_each_after(_node, _iter)                                      \
	for (_iter = (_node)->next; (_iter) != (_list); _iter = (_iter)->next)

#define list_for_each_safe(_list, _iter, _bkup)                                \
	for (_iter = (_list)->head;                                            \
	     (_iter) != (_list) && ((_bkup = (_iter)->next) || 1); _iter = (_bkup))

#define list_for_each_safe_after(_node, _iter, _bkup)                          \
	for (_iter = (_node)->next;                                            \
	     (_iter) != (_list) && ((_bkup = (_iter)->next) || 1); _iter = (_bkup))

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_entry_first(list, type, member)                                   \
	container_of((list)->head, type, member)

#define list_entry_next(item, member)                                          \
	container_of((item)->member.next, typeof(*(item)), member)

#define list_for_each_entry(item, list, member)                                \
	for (item = list_entry_first(list, typeof(*(item)), member);           \
	     &item->member != list; item = list_entry_next(item, member))

#ifdef __cplusplus
}
#endif

#endif // __CUTILS_LIST_H__
