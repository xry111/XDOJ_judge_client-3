/* xdoj_jc3_mem.c : define functions for memory control.
   Copyright (C) 2016-2017 Lab of ACM/ICPC, Xidian University.

This file is part of XDOJ Judge Client v3.

XDOJ Judge Client v3 is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

XDOJ Judge Client v3 is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with XDOJ Judge Client v3; see the file LICENSE.  If not see
<http://www.gnu.org/licenses/>.  */

#include <inttypes.h>
#include <errno.h>

#include "xdoj_jc3_io.h"
#include "xdoj_jc3_log.h"
#include "xdoj_jc3_mem.h"

/* Relative path to useful pseudo files.  */

static const char *CG_TASK = "memcg/cgroup.procs";
static const char *CG_MEM_LIMIT_B = "memcg/memory.limit_in_bytes";
static const char *CG_MEMSW_LIMIT_B = "memcg/memory.memsw.limit_in_bytes";
static const char *CG_MEMSW_USAGE_B = "memcg/memory.memsw.max_usage_in_bytes";

extern int xdoj_jc3_mem_setlimit(pid_t pid, intptr_t limit_b)
{
	/* Set memsw limit to maximum, to avoid memory limit > memsw limit.  */
	if (xdoj_jc3_io_fprintf(CG_MEMSW_LIMIT_B, "%" PRIdPTR, INTPTR_MAX) < 0) {
		LOG(LOG_ERR, "mem_setlimit: can not maximize memsw limit.");
		return -1;
	}

	/* Set memory limit first.  */
	if (xdoj_jc3_io_fprintf(CG_MEM_LIMIT_B, "%" PRIdPTR, limit_b) < 0) {
		LOG(LOG_ERR, "mem_setlimit: can not set memory limit.");
		return -1;
	}

	/* Set memsw limit then.  */
	if (xdoj_jc3_io_fprintf(CG_MEMSW_LIMIT_B, "%" PRIdPTR, limit_b) < 0) {
		LOG(LOG_ERR, "mem_setlimit: can not set memsw limit.");
		return -1;
	}

	/* Add pid into the cgroup.  */
	if (xdoj_jc3_io_fprintf(CG_TASK, "%" PRIdMAX, (intmax_t) pid) < 0) {
		LOG(LOG_ERR, "mem_setlimit: can not add task into cgroup.");
		return -1;
	}

	return 0;
}

extern intptr_t xdoj_jc3_mem_getusage_b(void)
{
	intptr_t ret;

	if (xdoj_jc3_io_fscanf(CG_MEMSW_USAGE_B, "%" PRIdPTR, &ret) != 1) {
		LOG(LOG_ERR, "mem_getusage_b: can not get memory usage.");
		ret = -1;
	}

	return ret;
}
