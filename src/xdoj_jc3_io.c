/* xdoj_jc3_cg.c : implement functions for file I/O.
   Copyright (C) 2017 Lab of ACM/ICPC, Xidian University.

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

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#include "xdoj_jc3_io.h"
#include "xdoj_jc3_log.h"

extern int xdoj_jc3_io_fscanf(const char* path, const char *format, ...)
{
	va_list ap;
	int ret;

	FILE *f = fopen(path, "r");
	if (!f) {
		LOG(LOG_ERR, "fopen: %m");
		return -1;
	}

	va_start(ap, format);

	errno = 0;
	ret = vfscanf(f, format, ap);

	if (errno)
		LOG(LOG_ERR, "vfscanf: %m");

	fclose(f);
	return ret;
}

extern int xdoj_jc3_io_fprintf(const char* path, const char *format, ...)
{
	va_list ap;
	int ret;

	FILE *f = fopen(path, "w");
	if (!f) {
		LOG(LOG_ERR, "fopen: %m");
		return -1;
	}

	va_start(ap, format);

	errno = 0;
	ret = vfprintf(f, format, ap);

	if (errno)
		LOG(LOG_ERR, "vfprintf: %m");

	fclose(f);
	return ret;
}
