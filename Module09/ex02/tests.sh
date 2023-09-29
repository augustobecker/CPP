#!/bin/sh
make && clear
NAME=PmergeMe

echo
echo "\e[1;32mTest 1 - sort 1 number\e[0m"
./$NAME 1

echo
echo "\e[1;32mTest 2 - sort 2 number\e[0m"
./$NAME 2 1

echo
echo "\e[1;32mTest 3 - sort 3 number\e[0m"
./$NAME 2 1 3

echo
echo "\e[1;32mTest 4 - sort 4 number\e[0m"
./$NAME 2 0 4 3

echo
echo "\e[1;32mTest 5 - sort 5 number\e[0m"
./$NAME 5 2 0 4 3

echo
echo "\e[1;32mTest 6 - sort 14 numbers from 0 to 13\e[0m"
./$NAME `shuf -i 0-13 -n 14 | xargs`

echo
echo "\e[1;32mTest 7 - sort 15 numbers from 0 to 14\e[0m"
./$NAME `shuf -i 0-14 -n 15 | xargs`

echo
echo "\e[1;32mTest 8 - sort 100 numbers from 0 to 99\e[0m"
./$NAME `shuf -i 0-99 -n 100 | xargs`

echo
echo "\e[1;32mTest 9 - sort 1000 numbers from 0 to 999\e[0m"
./$NAME `shuf -i 0-999 -n 1000 | xargs`

echo
echo "\e[1;32mTest 10 - sort 3000 numbers from 0 to 2999\e[0m"
./$NAME `shuf -i 0-2999 -n 3000 | xargs`

echo
echo "\e[1;31mError tests\e[0m"
echo "\e[1;31mTest 11 - No arguments\e[0m"
./$NAME

echo
echo "\e[1;31mTest 12 - Not an int: 10 1 2147483648\e[0m"
./$NAME 10 1 2147483648

echo
echo "\e[1;31mTest 13 - Not a number: 10 a 2 3 321 1 42 42\e[0m"
./$NAME 10 a 2 3 321 1 42 42

echo
echo "\e[1;31mTest 14 - All in one argument: \"42 42 0\"\e[0m"
./$NAME "42 42 0"

echo
echo "\e[1;31mTest 15 - Negative numbers: 10 984 -2 3 321 1 42 -42\e[0m"
./$NAME 10 984 -2  3 321 1 42 -42

echo
echo "\e[1;31mTest 16 - Duplicates: 1 42 42 0\e[0m"
./$NAME 1 42 42 0