@echo off
color 2
cd %~dp0/build
echo heyy buddy you about to do a saucing
pause
echo..
echo..

::Get N
set /P NUMBER="Enter a positive number: " 

echo..
echo.. 
::Run c code
singleFib.exe %NUMBER%

echo Check output/fib(n) for the results
pause
exit