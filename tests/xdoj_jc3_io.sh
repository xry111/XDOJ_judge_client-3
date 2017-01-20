#!/bin/sh

source ./color.sh

rm -f /tmp/xdoj_jc3_test_$$
./xdoj_jc3_io.exe /tmp/xdoj_jc3_test_$$

ret=$?

if [ ${ret} = 0 ]; then
	echo -e "${GREEN}xdoj_jc3_io succeed.${NORMAL}"
else
	echo -e "${RED}xdoj_jc3_io failed.${NORMAL}"
fi

rm -f /tmp/xdoj_jc3_test_$$

exit ${ret}
