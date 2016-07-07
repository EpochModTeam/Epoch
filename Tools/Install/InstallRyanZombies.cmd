@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410

:: Use -mod line with quotes to support spaces in folder
:: Example: -mod="@Epoch;@Zombies and Demons;"

:: Install Ryans Zombies and Demons

SET MODFOLDER=@Zombies and Demons
SET ARMAWORKSHOPID=501966277

:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"

:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit

:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"

:: remove old bikey key
del "%ARMASVRPATH%\Keys\RyanD.bikey"

:: copy latest bikey to server
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"
