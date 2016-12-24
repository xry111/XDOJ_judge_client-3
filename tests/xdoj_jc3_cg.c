#include <errno.h>
#include <error.h>
#include <inttypes.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "xdoj_jc3_cg.h"

/* Try to set limit to 16M.  */
int test_io()
{
    int64_t value;

    /* First memory.  Guarantee that the memsw limit is not less than
	   memory limit.  */
    if (xdoj_jc3_cg_write_value(XDOJ_JC3_CG_MEM_LIMIT_B, 16 << 20, "w") < 0)
        error_at_line(1, errno, __FILE__, __LINE__, "write_value");

    /* Then memsw.  */
    if (xdoj_jc3_cg_write_value(XDOJ_JC3_CG_MEMSW_LIMIT_B, 16 << 20, "w") < 0)
        error_at_line(1, errno, __FILE__, __LINE__, "write_value");

    /* Read out the limit, double check.  */
    value = xdoj_jc3_cg_read_value(XDOJ_JC3_CG_MEM_LIMIT_B);
    if (value < 0)
        error_at_line(1, errno, __FILE__, __LINE__, "read_value");
    if (value != 16 << 20)
        error_at_line(1, 0, __FILE__, __LINE__,
            "expected value to be %" PRId64 ", but actually %" PRId64 ".", (int64_t)(1 << 20), value);

    value = xdoj_jc3_cg_read_value(XDOJ_JC3_CG_MEMSW_LIMIT_B);
    if (value < 0)
        error_at_line(1, errno, __FILE__, __LINE__, "read_value");
    if (value != 16 << 20)
        error_at_line(1, 0, __FILE__, __LINE__,
            "expected value to be %" PRId64 ", but actually %" PRId64 ".", (int64_t)(1 << 20), value);
    return 0;
}

/* Try to create a child to eat memory.  */
int test_run()
{
    int64_t value;

    pid_t pid = fork();
    if (pid < 0)
        error_at_line(1, errno, __FILE__, __LINE__, "fork");

    if (pid) {
        int status;

        if (xdoj_jc3_cg_write_value(XDOJ_JC3_CG_TASK, pid, "a") < 0)
            error_at_line(1, errno, __FILE__, __LINE__, "write_value");

        if (waitpid(pid, &status, 0) != pid)
            error_at_line(1, errno, __FILE__, __LINE__, "waitpid");

        if (WIFEXITED(status))
            error_at_line(1, 0, __FILE__, __LINE__, "expect the child"
                                                    "to be killed, but actually exited with status %d.",
                (int)WEXITSTATUS(status));

        if (WTERMSIG(status) != SIGKILL) {
            error_at_line(1, 0, __FILE__, __LINE__, "expect the child"
                                                    "to be killed by SIGKILL, but actually signal %d.",
                (int)WTERMSIG(status));
        }

        value = xdoj_jc3_cg_read_value(XDOJ_JC3_CG_MEMSW_USAGE_B);
        if (value < 0)
            error_at_line(1, errno, __FILE__, __LINE__, "read_value");
        if (value != 16 << 20)
            error_at_line(1, 0, __FILE__, __LINE__,
                "expected value to be %" PRId64 ", but actually %" PRId64 ".", (int64_t)(1 << 20), value);
    } else {
        /* wait for the parent add me into the cg.  */
        sleep(1);
        static volatile char mem[32 << 20];
        for (int i = 0; i < 32 << 20; i++)
            mem[i] = 0x55;
        (void)(&mem);
        exit(0);
    }
    return 0;
}

int main()
{
    puts("test_io:");
    test_io();
    puts("successful!");
    puts("test_run:");
    test_run();
    puts("successful!");
    return 0;
}
