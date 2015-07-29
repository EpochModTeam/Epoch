@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410
:: Workshop IDs: EpochExperimental = 455221958, Normal Epoch = 421839251
SET ARMAWORKSHOPID=455221958
:: remove mod folder
rd /s/q "%ARMASVRPATH%\@Epoch"
:: remove cache C:\Users\Administrator\Downloads\steamcmd\steamapps\workshop
del "steamapps\workshop\appworkshop_%ARMAAPPID%.acf"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit
:: copy files back to server 
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\@Epoch"
