#!/bin/sh

source ./color.sh

if [ $UID != 0 ]; then
	echo -e "${BLUE}xdoj_jc3_mem skipped: need root permittion.${NORMAL}"
	exit 0;
fi

mkdir ${CG_MOUNT}/$$ &&
ln -sv ${CG_MOUNT}/$$ ./memcg &&
./xdoj_jc3_mem.exe;

ret=$?;

if [ ${ret} = 0 ]; then
	echo -e "${GREEN}xdoj_jc3_mem succeeded.${NORMAL}"
else
	echo -e "${RED}xdoj_jc3_mem failed.${NORMAL}"
fi

rm memcg
rmdir ${CG_MOUNT}/$$;
exit ${ret};
