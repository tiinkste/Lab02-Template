#!/bin/bash
# Exit the script if any commands return with non-zero code
set -e
# DO NOT MODIFY ANY OF THE LINES ABOVE

# TODO: Fill in this file with commands to compile, execute, and check output

gcc -Wall -Werror -std=c99 ./src/ex2q1.c -o ./src/ex2q1.out

./src/ex2q1.out < Testcases/1-1-input.txt >| Testcases/1-1-student.txt

diff -u Testcases/1-1-output.txt Testcases/1-1-student.txt

./src/ex2q1.out < Testcases/1-2-input.txt >| Testcases/1-2-student.txt

diff -u Testcases/1-2-output.txt Testcases/1-2-student.txt

./src/ex2q1.out < Testcases/1-3-input.txt >| Testcases/1-3-student.txt

diff -u Testcases/1-3-output.txt Testcases/1-3-student.txt

./src/ex2q1.out < Testcases/1-4-input.txt >| Testcases/1-4-student.txt

diff -u Testcases/1-4-output.txt Testcases/1-4-student.txt

./validate.sh
