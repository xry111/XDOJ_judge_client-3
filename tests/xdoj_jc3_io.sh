#!/bin/sh

rm -f /tmp/xdoj_jc3_test_$$

./runtest.sh xdoj_jc3_io.exe /tmp/xdoj_jc3_test_$$
ret=$?

rm -f /tmp/xdoj_jc3_test_$$

exit ${ret}
