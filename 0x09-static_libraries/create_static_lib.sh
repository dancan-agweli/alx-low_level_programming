#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar -rc lball.a *.o
ranlib liball.a
