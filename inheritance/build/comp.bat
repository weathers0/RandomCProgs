::Change directory to where program is
cd %~dp0

gcc -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o inheritance inheritance.c -lm

@echo off
pause
exit