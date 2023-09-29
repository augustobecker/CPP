#!/bin/sh
make && clear
NAME=PmergeMe

echo
echo "1. Sort 1 number"
./$NAME 42

echo
echo "2. Sort 2 numbers"
./$NAME 42 1

echo
echo "3. Sort 3 numbers"
./$NAME 11 42 1

echo
echo "4. Sort 5 numbers"
./$NAME 10 1 4 2 8

echo
echo "5. Sort 10 numbers"
./$NAME 5 11 2 0 23 4 3 33 1 9

echo
echo "6. Sort 30 numbers"
./$NAME `shuf -i 0-29 -n 30 | xargs`

echo
echo "7. Sort 50 numbers"
./$NAME `shuf -i 0-49 -n 50 | xargs`

echo
echo "8. Sort 100 numbers"
./$NAME `shuf -i 0-99 -n 100 | xargs`

echo
echo "9. Sort 1000 numbers"
./$NAME `shuf -i 0-999 -n 1000 | xargs`

echo
echo "10. Sort 3000 numbers"
./$NAME `shuf -i 0-2999 -n 3000 | xargs`

echo
echo "Fail tests"
echo "11. Missing Arguments"
./$NAME

echo
echo "12. Over Int Max: 10 1 2147483648"
./$NAME 2 1 2147483648

echo
echo "13. Not a number: 13 4 1 505 X 42"
./$NAME 13 4 1 505 X 42

echo
echo "14. All in one argument: \"3 1 2\""
./$NAME "3 1 2"

echo
echo "15. Negative number: 13 4 1 505 -5 42"
./$NAME 13 4 1 505 -5 42

echo
echo "16. Duplicates: 11 42 42 8"
./$NAME 11 42 42 8