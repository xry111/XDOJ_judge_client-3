/* xdoj_jc3_mem.c : test functions for memory control.
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

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "xdoj_jc3_mem.h"

int main(void)
{
	pid_t pid = fork();
	if (pid) {
		int status;
		intptr_t usage;

		if (pid < 0) {
			perror("fork");
			return -1;
		}

		if (xdoj_jc3_mem_setlimit(pid, 32<<20) < 0) {
			perror("mem_setlimit");
			return -1;
		}

		if (waitpid(pid, &status, 0) < 0) {
			perror("waitpid");
			return -1;
		}

		if (!WIFSIGNALED(status)) {
			fprintf(stderr, "The child is not killed. status = %d\n", status);
			return -1;
		}

		usage = xdoj_jc3_mem_getusage_b();
		if (usage < 0) {
			perror("waitpid");
			return -1;
		}

		if (usage != 32<<20) {
			fprintf(stderr, "Expect usage to be %" PRIdPTR ", but actually %"
				PRIdPTR ".\n", (intptr_t) (32<<20), usage);
			return -1;
		}
	} else {
		/* Wait the parent to set memory limit.  */
		usleep(500);

		/* Use a lot of memory.  */
		volatile char *mem = (volatile char *) malloc(64<<20);
		for (int i = 0; i < 64<<20; i++)
			mem[i] = 0;
	}
	return 0;
}
