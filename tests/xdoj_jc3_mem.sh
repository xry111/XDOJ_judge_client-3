#!/bin/sh

source ./color.sh

if [ $UID != 0 ]; then
	echo -e "${BLUE}xdoj_jc3_mem skipped: need root permittion.${NORMAL}"
	exit 0;
fi

mkdir ${CG_MOUNT}/$$ &&
ln -sv ${CG_MOUNT}/$$ ./memcg &&
./runtest.sh xdoj_jc3_mem.exe;

ret=$?;

rm memcg
rmdir ${CG_MOUNT}/$$;
exit ${ret};
