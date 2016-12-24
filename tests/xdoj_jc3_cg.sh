#!/bin/sh

if [ $UID != 0 ]; then
	echo "$0: test skipped: need root permittion."
	exit 0;
fi

mkdir ${CG_MOUNT}/$$ &&
ln -sv ${CG_MOUNT}/$$ ./memcg &&
./xdoj_jc3_cg.exe;

ret=$?;

rm memcg
rmdir ${CG_MOUNT}/$$;
exit ${ret};
