/* xdoj_jc3_security_code.h : declare security code.
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

#ifndef XDOJ_JC3_SECURITY_CODE_H
#define XDOJ_JC3_SECURITY_CODE_H

#include <stdint.h>

/* This 64-bit security code is used by judge's code to distinguish it
   from participants'.  The value is from /dev/urandom for each time of
   make.  */
extern const uint64_t xdoj_jc3_security_code;

#endif
