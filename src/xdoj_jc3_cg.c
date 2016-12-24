/* xdoj_jc3_cg.h : define functions for cgroup memory control.
   Copyright (C) 2016 Lab of ACM/ICPC, Xidian University.

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
#include <stdio.h>

#include "xdoj_jc3_cg.h"

int64_t xdoj_jc3_cg_read_value(const char* path)
{
    int64_t ret = -1;

    FILE* fp = fopen(path, "r");
    if (!fp)
        return -1;

    if (fscanf(fp, "%" PRId64, &ret) != 1)
        ret = -1;

    fclose(fp);
    return ret;
}

int xdoj_jc3_cg_write_value(const char* path, int64_t value, const char* mode)
{
    int ret = 0;

    FILE* fp = fopen(path, mode);
    if (!fp)
        return -1;

    if (fprintf(fp, "%" PRId64, value) < 0)
        ret = -1;

    fclose(fp);
    return ret;
}

/* Relative path to useful pseudo files.  */

#ifndef CG
#define CG "memcg"
#endif

const char* XDOJ_JC3_CG_TASK = CG "/cgroup.procs";
const char* XDOJ_JC3_CG_MEM_LIMIT_B = CG "/memory.limit_in_bytes";
const char* XDOJ_JC3_CG_MEMSW_LIMIT_B = CG "/memory.memsw.limit_in_bytes";
const char* XDOJ_JC3_CG_MEMSW_USAGE_B = CG "/memory.memsw.usage_in_bytes";
