@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=changeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410
SET MODFOLDER=@Epoch
:: Workshop IDs: EpochExperimental = 1399517607 Normal Epoch = 421839251
SET ARMAWORKSHOPID=1399517607
:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
del "%ARMASVRPATH%\Keys\epoch*.bikey"
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"
