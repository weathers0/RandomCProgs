@echo off
cd %~dp0/build
color 2
echo heyy buddy you about to do a saucing
pause
echo.
echo.

::Get N
set /P NUMBER="Enter a positive number: " 

echo.
echo. 

::Run c code
inheritance.exe %NUMBER%
echo.

::Change to output directory so mr Batty can find the outfile
cd ../output
pause
echo.

::Generate filename
set PATH=inheritance(%NUMBER%).txt

::Print first line (gen0)
set /p gen0=<%PATH%
echo %gen0%

echo Check inheritance(%NUMBER%).txt for the full results!
pause
exit