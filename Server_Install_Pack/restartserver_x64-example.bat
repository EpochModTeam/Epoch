@echo off

:: Turn off all firewall rules
echo Disabling firewall rules for this server
netsh advfirewall firewall delete rule name="a3Epoch" program="C:\EpochServer\Epochserver_x64.exe"
timeout 2

:: MAKE SURE ALL TASKS ARE REALLY STOPPED
echo Making sure all instances of this server have stopped
taskkill /f /fi "status eq not responding" /im Epochserver_x64.exe
taskkill /f /im Epochserver_x64.exe
timeout 2

:: RESTARTING THE ARMA 3 SERVER BE SURE TO EDIT THIS TO YOUR SERVER .EXE LOCATION -NOTE ALSO THIS IS WHERE YOU DEFINE WHERE YOU CONFIG.CFG IS
echo Starting ARMA 3 Server...
C:\Windows\System32\cmd.exe /C start "arma3"  "C:\EpochServer\Epochserver_x64.exe"  "[email protected];" "[email protected];" -config=C:\EpochServer\sc\server.cfg -port=2302 -profiles=sc -cfg=C:\EpochServer\sc\basic.cfg -name=sc -BEPath=C:\EpochServer\battleye -autoINIT -Loadmissiontomemory
echo ARMA 3 Server has started
timeout 60

:: THIS RUNS THE SERVER MONITOR FOR YOU SO YOU DON'T FORGET
echo Starting Server Monitor Loop
set ServerMonitorPath="C:\Epochserver"
cd /d %ServerMonitorPath%
start "" "servermonitor.bat"
echo Server Monitor has started. Have Fun
timeout 5

:: Turn On Firewall rule
timeout 10
echo Turning on Firewall Rule to allow server network traffic
netsh advfirewall firewall add rule name="a3Epoch" dir=in action=allow program="C:\Epochserver\Epochserver_x64.exe" enable=yes
echo Firewall is on and players can join
timeout 5
@exit 