#!/bin/bash

rm trace.txt
cp ../push_swap .
cp ../checker_linux .
chmod 764 check_script.sh
./check_script.sh 1 >> trace.txt
./check_script.sh 2 >> trace.txt
./check_script.sh 3 >> trace.txt
./check_script.sh 4 >> trace.txt
./check_script.sh 5 >> trace.txt
./check_script.sh 6 >> trace.txt
rm actions.txt
rm push_swap
rm checker_linux
echo "$(cat trace.txt | grep "OK" | wc -l) OK"
echo "$(cat trace.txt | grep "KO" | wc -l) KO"
cat trace.txt | grep "KO"
