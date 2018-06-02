::@ECHO OFF

SET SOURCEPATH="F:\GitHub Personal\Epoch\Server_Install_Pack"
SET WORKSHOPPATH="F:\GitHub Personal\Epoch-HiveTest\@epochhive"

:: Workshop IDs:
:: EpochExperimental = 1399517607
:: Normal Epoch = 421839251

:: copy mod from steamcmd cache to server
xcopy /s/e/y/q/i "F:\GitHub Personal\Epoch\Server_Install_Pack\mpmissions" "F:\GitHub Personal\Epoch-HiveTest\@epochhive\mpmissions"
xcopy /s/e/y/q/i "F:\GitHub Personal\Epoch\Server_Install_Pack\@epochhive\addons" "F:\GitHub Personal\Epoch-HiveTest\@epochhive\addons"
xcopy /s/e/y/q/i "F:\GitHub Personal\Epoch\Server_Install_Pack\sc\battleye" "F:\GitHub Personal\Epoch-HiveTest\@epochhive\sc\battleye"


START "" /WAIT "F:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\Publisher\PublisherCmd.exe" update /id:1399533789 /changeNote:"See Changelogs: https://github.com/EpochModTeam/Epoch/tree/experimental/Changelogs" /path:%WORKSHOPPATH%
