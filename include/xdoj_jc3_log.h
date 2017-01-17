/* xdoj_jc3_log.h : macro for syslog entries.
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

#ifndef XDOJ_JC3_LOG_H
#define XDOJ_JC3_LOG_H 1

#include <syslog.h>

/* Log entry with the location in code.
   _format must be a string literal.  */
#define LOG(_level, _format, ...) \
	syslog(_level, "%s [%s:%d]: " _format, __FUNCTION__, __FILE__, \
		__LINE__, ##__VA_ARGS__)

/* Control LOG_DEBUG messages.  */
#define DEBUG_ON() setlogmask(LOG_UPTO(LOG_DEBUG))
#define DEBUG_OFF() setlogmask(LOG_UPTO(LOG_INFO))

#endif
