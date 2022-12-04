#ifndef __CUTILS_WORKQUEUE_H__
#define __CUTILS_WORKQUEUE_H__

#include <stdbool.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

struct q_work {
	void *data;
	void (*func)(void *);
	const char *name; // optional
};

int c_work_schedule_delayed(struct q_work *work, int delay_ms);
static inline int c_work_schedule_now(struct q_work *work)
{
	return c_work_schedule_delayed(work, 0);
}

#ifdef __cplusplus
}
#endif

#endif // __CUTILS_WORKQUEUE_H__
