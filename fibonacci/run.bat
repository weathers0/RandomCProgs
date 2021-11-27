@echo off
cd %~dp0/exe
echo heyy buddy you about to do a saucing
pause
echo..
echo..
color 2

::Get N
set /P NUMBER="Enter a positive number: " 

echo..
echo.. 
::Run c code
fibonacci.exe %NUMBER%

echo Check textOuts/fibOut.txt for the results
pause
exit