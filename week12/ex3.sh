touch fileA
touch fileB

dd if=/dev/zero of=fileA bs=1048576 count=1

echo -DBUF_SIZE=2 >> ex3.txt
echo File size = 1mb >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=2
time ./copy fileA fileB
rm fileB


echo -DBUF_SIZE=2 >> ex3.txt
echo -D_SYNC=1 >> ex3.txt
echo File size = 1mb >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=2 -D_SYNC=1
time ./copy fileA fileB
rm fileB


echo -DBUF_SIZE=128 >> ex3.txt
echo File size = 1mb >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=128
time ./copy fileA fileB
rm fileB



rm fileA
dd if=/dev/zero of=fileA bs=31457280 count=1


echo -DBUF_SIZE=2 >> ex3.txt
echo File size = 30mb >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=2
time ./copy fileA fileB
rm fileB


echo -DBUF_SIZE=2 >> ex3.txt
echo -D_SYNC=1 >> ex3.txt
echo File size = 30mb >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=2 -D_SYNC=1
time ./copy fileA fileB  
rm fileB


echo -DBUF_SIZE=128 >> ex3.txt
echo File size = 30mb >> ex3.txt
gcc copy.c -o copy -DBUF_SIZE=128
time ./copy fileA fileB
rm fileB


rm fileA

