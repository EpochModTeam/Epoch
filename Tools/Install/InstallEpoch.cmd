@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410

:: Workshop IDs:
:: EpochExperimental = 1399517607
:: Normal Epoch = 421839251
SET ARMAWORKSHOPID=421839251

:: remove mod folder
rd /s/q "%ARMASVRPATH%\@Epoch"

:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit

:: copy mod from steamcmd cache to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\@Epoch"
