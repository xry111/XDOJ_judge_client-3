/* xdoj_jc3_cg.h : declare functions for cgroup memory control.
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

#ifndef XDOJ_JC3_CG_H
#define XDOJ_JC3_CG_H 1

#include <stdint.h>

/* Useful functions operating cgroup sysfs pseudo files.  */

extern int64_t xdoj_jc3_cg_read_value(const char* path);
extern int xdoj_jc3_cg_write_value(const char* path, int64_t value, const char* mode);

/* Relative path to useful pseudo files.  */

extern const char* XDOJ_JC3_CG_TASK;
extern const char* XDOJ_JC3_CG_MEM_LIMIT_B;
extern const char* XDOJ_JC3_CG_MEMSW_LIMIT_B;
extern const char* XDOJ_JC3_CG_MEMSW_USAGE_B;

#endif
