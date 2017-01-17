rm -f /tmp/xdoj_jc3_test_$$
./xdoj_jc3_io.exe /tmp/xdoj_jc3_test_$$

ret=$?

if [ ${ret} = 0 ]; then
	echo "xdoj_jc3_io: successful."
else
	echo "xdoj_jc3_io: fail."
fi

rm -f /tmp/xdoj_jc3_test_$$

exit ${ret}
