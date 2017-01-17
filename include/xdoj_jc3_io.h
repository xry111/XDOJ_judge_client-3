/* xdoj_jc3_io.h : declare simple file I/O functions.
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

#ifndef XDOJ_JC3_IO_H
#define XDOJ_JC3_IO_H 1

/* Useful functions operating files.  */

extern int xdoj_jc3_io_fscanf(const char* path, const char *format, ...)
	__attribute__((format (scanf, 2, 3)));

extern int xdoj_jc3_io_fprintf(const char* path, const char *format, ...)
	__attribute__((format (printf, 2, 3)));

#endif
