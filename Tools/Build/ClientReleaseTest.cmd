::@ECHO OFF

SET WORKSHOPPATH="G:\SteamLibrary\steamapps\common\Arma 3\@epoch"

:: Workshop IDs:
:: EpochExperimental = 455221958
:: Normal Epoch = 421839251

START "" /WAIT "F:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\Publisher\PublisherCmd.exe" update /id:455221958 /changeNote:"See Changelogs: https://github.com/EpochModTeam/Epoch/tree/experimental/Changelogs" /path:%WORKSHOPPATH%
