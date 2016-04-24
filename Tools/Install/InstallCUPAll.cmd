@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410

:: Use -mod line with quotes to support spaces in folder
:: Example: -mod="@epoch;@CBA_A3;@CUP Units;@CUP Vehicles;@CUP Weapons;@CUP Terrains - Core;@CUP Terrains - Maps;"

:: Install CUP CORE
SET MODFOLDER=@CUP Terrains - Core
SET ARMAWORKSHOPID=583496184
:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
:: Remove old bikey
del "%ARMASVRPATH%\Keys\cup_terrains_core-*.bikey"
:: add new bikey
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"

:: Install CUP MAPS
SET MODFOLDER=@CUP Terrains - Maps
SET ARMAWORKSHOPID=583544987
:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
:: Remove old bikey
del "%ARMASVRPATH%\Keys\cup_terrains_maps-*.bikey"
:: add new bikey
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"

:: Install CUP Vehicles
SET ARMAWORKSHOPID=541888371
SET MODFOLDER=@CUP Vehicles
:: remove mod folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
del "%ARMASVRPATH%\Keys\cup_vehicles-*.bikey"
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"

:: Install CBA
SET ARMAWORKSHOPID=450814997
SET MODFOLDER=@CBA_A3
:: remove mod folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
del "%ARMASVRPATH%\Keys\cba_*.bikey"
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"

:: Install CUP Weapons
SET ARMAWORKSHOPID=497660133
SET MODFOLDER=@CUP Weapons
:: remove mod folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
del "%ARMASVRPATH%\Keys\cup_weapons-*.bikey"
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"

:: Install CUP Units
SET ARMAWORKSHOPID=497661914
SET MODFOLDER=@CUP Units
:: remove mod folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"
:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% validate +quit
:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
del "%ARMASVRPATH%\Keys\cup_units-*.bikey"
xcopy /s/e/y/q/i "%ARMASVRPATH%\%MODFOLDER%\Keys" "%ARMASVRPATH%\Keys"
