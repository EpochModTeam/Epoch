@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410
SET ARMAWORKSHOPID=421839251

:: remove mod folder
rd /s/q "%ARMASVRPATH%\@Epoch"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server 
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\@Epoch"
:: steamcmd.exe +login %STEAMUN% %STEAMPW% +force_install_dir "%ARMASVRPATH%" "+app_update %ARMAAPPID%" validate +quit
