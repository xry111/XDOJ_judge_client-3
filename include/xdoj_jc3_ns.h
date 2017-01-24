/* xdoj_jc3_ns.h : clone(2) namespaces options
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

#ifndef XDOJ_JC3_NS_H
#define XDOJ_JC3_NS_H 1

#include <sched.h>

#ifdef _XDOJ_JC3_USE_IPC_NS
#define XDOJ_JC3_CLONE_NEWIPC CLONE_NEWIPC
#else
#define XDOJ_JC3_CLONE_NEWIPC 0
#endif

#ifdef _XDOJ_JC3_USE_NET_NS
#define XDOJ_JC3_CLONE_NEWNET CLONE_NEWNET
#else
#define XDOJ_JC3_CLONE_NEWNET 0
#endif

#ifdef _XDOJ_JC3_USE_PID_NS
#define XDOJ_JC3_CLONE_NEWPID CLONE_NEWPID
#else
#define XDOJ_JC3_CLONE_NEWPID 0
#endif

#ifdef _XDOJ_JC3_USE_UTS_NS
#define XDOJ_JC3_CLONE_NEWUTS CLONE_NEWUTS
#else
#define XDOJ_JC3_CLONE_NEWUTS 0
#endif

#define XDOJ_JC3_CLONE_NS (CLONE_NEWNS | CLONE_NEWUSER | \
XDOJ_JC3_CLONE_NEWIPC | XDOJ_JC3_CLONE_NEWNET | XDOJ_JC3_CLONE_NEWPID | \
XDOJ_JC3_CLONE_NEWUTS)

#endif
