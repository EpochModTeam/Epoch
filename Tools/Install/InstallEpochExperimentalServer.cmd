@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=changeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410
SET ARMAWORKSHOPID=1399533789
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\@EpochHive"
:: copy battleye files to live
xcopy /s/e/y/q/i "%ARMASVRPATH%\@EpochHive\sc\BattlEye" "%ARMASVRPATH%\SC\BattlEye"
:: update mission files
xcopy /s/e/y/q/i "%ARMASVRPATH%\@EpochHive\MPMissions" "%ARMASVRPATH%\MPMissions"
