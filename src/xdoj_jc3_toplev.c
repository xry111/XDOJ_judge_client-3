/* xdoj_jc3_toplev.c : top level function.
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "xdoj_jc3_toplev.h"

int xdoj_jc3_toplev(int argc, char** argv)
{
    /* TODO: This is only a dummy.  */
    printf("%s: dummy.\n", argv[0]);
    execl("/usr/bin/fortune", "fortune", NULL);
    return argc;
}
