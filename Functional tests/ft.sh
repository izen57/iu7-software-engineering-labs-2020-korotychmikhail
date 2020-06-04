#!/bin/bash
gcc -c bin_to_hex.c
gcc -c main.c
gcc -o main.exe bin_to_hex.o main.o
rm main.o
rm bin_to_hex.o
for ((i=1; i<=5; i++))
do
echo "test #$i"
./main.exe 'Functional tests'/in_$i.txt 'Functional tests'/actual_out_$i.txt
diff 'Functional tests'/expected_out_$i.txt 'Functional tests'/actual_out_$i.txt
done
rm main.exe