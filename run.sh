#!/bin/sh

set -xe
mkdir -p bin/
gcc -Wall -Wextra -o bin/$1 $1.c
./bin/$1
