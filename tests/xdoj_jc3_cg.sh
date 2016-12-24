#!/bin/sh

mkdir ${CG_MOUNT}/$$ &&
ln -sv ${CG_MOUNT}/$$ ./memcg &&
./xdoj_jc3_cg.exe;

ret=$?;

rm memcg
rmdir ${CG_MOUNT}/$$;
exit ${ret};
