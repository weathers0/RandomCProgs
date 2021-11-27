::Change directory to where program is
cd %~dp0

::Convert .c files to .o
gcc -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o fibonacci.o fibonacci.c
gcc -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o helper.o helper.c
::TODO: xFind out what Qunused-arguments means/ does

::Combine .o files into single .exe
gcc -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o fibonacci fibonacci.o helper.o -lm

@echo off

::Delete .o files
DEL *.o

pause
exit