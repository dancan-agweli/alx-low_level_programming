#!/bin/bashh
gcc -Wall -Pedantic -Werror -Wextra -c *.c
ar -rc liball.a
ranlib liball.a
