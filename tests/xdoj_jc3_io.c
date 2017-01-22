/* xdoj_jc3_io.c : file I/O testing.
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

#include "xdoj_jc3_io.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int val;

	(void) argc;

	if (xdoj_jc3_io_fprintf(argv[1], "%d", 20170107) < 0) {
		perror("io_fprintf");
		return 1;
	}

	if (xdoj_jc3_io_fscanf(argv[1], "%d", &val) != 1) {
		perror("io_fscanf");
		return 1;
	}

	if (val != 20170107) {
		fprintf(stderr, "expect val to be %d, but actually %d.",
			20170107, val);
		return 1;
	}

	return 0;
}
