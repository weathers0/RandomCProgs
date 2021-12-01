@echo off
color 3
cd %~dp0
echo bench that bitch

::Run compiled exe with a fixed number
fibonacci.exe 100000

echo Check fibbyg.txt for the results
pause
exit