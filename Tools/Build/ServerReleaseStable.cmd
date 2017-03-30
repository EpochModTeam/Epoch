::@ECHO OFF

SET SOURCEPATH="F:\GitHub Personal\Epoch\Server_Install_Pack"
SET WORKSHOPPATH="F:\GitHub Personal\Epoch-HiveStable\@epochhive"

:: copy mod from steamcmd cache to server
xcopy /s/e/y/q/i "F:\GitHub Personal\Epoch\Server_Install_Pack\mpmissions" "F:\GitHub Personal\Epoch-HiveStable\@epochhive\mpmissions"
xcopy /s/e/y/q/i "F:\GitHub Personal\Epoch\Server_Install_Pack\@epochhive\addons" "F:\GitHub Personal\Epoch-HiveStable\@epochhive\addons"
xcopy /s/e/y/q/i "F:\GitHub Personal\Epoch\Server_Install_Pack\sc\battleye" "F:\GitHub Personal\Epoch-HiveStable\@epochhive\sc\battleye"


START "" /WAIT "F:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\Publisher\PublisherCmd.exe" update /id:601772725 /changeNote:"See Changelogs: https://github.com/EpochModTeam/Epoch/tree/release/Changelogs" /path:%WORKSHOPPATH%
