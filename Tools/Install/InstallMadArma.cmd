@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410

:: Use -mod line with quotes to support spaces in folder
:: Example: -mod="@Epoch;@madarma;"

:: Install Mad Arma http://steamcommunity.com/sharedfiles/filedetails/?id=815962700

SET MODFOLDER=@madarma
SET ARMAWORKSHOPID=815962700

:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"

:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit

:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"

:: remove old bikey key
del "%ARMASVRPATH%\Keys\MadArmA*.bikey"

:: copy latest bikey to server
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"
