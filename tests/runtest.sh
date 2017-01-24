#!/bin/sh

source ./color.sh

./$@

ret=$?

if [ ${ret} = 0 ]; then
	echo -e "${GREEN}$1 succeed.${NORMAL}"
else
	echo -e "${RED}$1 failed.${NORMAL}"
fi

exit ${ret}
