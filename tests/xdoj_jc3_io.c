#include "xdoj_jc3_io.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int val;

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
