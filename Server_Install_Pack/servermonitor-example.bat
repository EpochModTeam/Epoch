@echo off
::IMPORTANT TO NAME IT SO WE CAN KILL IT
title servermonitor.bat
:start
C:\Windows\System32\tasklist /FI "IMAGENAME eq Epochserver_x64.exe" 2>NUL | C:\Windows\System32\find /I /N "Epochserver_x64.exe">NUL
if "%ERRORLEVEL%"=="0" goto loop
echo Server is not running, will be started now 
start "" /min /wait "c:\EpochServer\restartserver_x64.bat - Shortcut" 
timeout 30
echo Server started succesfully
exit
goto started
:loop
cls
echo Server is already running, running monitoring loop
:started
::THE 80 REFERS TO SECONDS AND HOW OFTEN IT WILL CHECK,YOU CAN SET IT TO WHATEVER YOU WANT. I JUST DONT WANT MY SERVER DOWN FOR MUCH LONGER THAN THAT!
::New error fault kill, will check for err fault and clear it and hopefully restart, a little more promise but no guarantee :)
taskkill /f /im WerFault.exe /fi "WINDOWTITLE eq Arma 3"
C:\Windows\System32\timeout /t 150
C:\Windows\System32\tasklist /FI "IMAGENAME eq Epochserver_x64.exe" 2>NUL | C:\Windows\System32\find /I /N "Epochserver_x64.exe">NUL
if "%ERRORLEVEL%"=="0" goto loop
goto start