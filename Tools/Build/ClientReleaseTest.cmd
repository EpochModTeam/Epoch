::@ECHO OFF
SET TOOLSPATH=F:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools
SET WORKSHOPPATH=G:\SteamLibrary\steamapps\common\Arma 3\@epoch
SET CHANGELOG="See Changelogs: https://github.com/EpochModTeam/Epoch/tree/experimental/Changelogs"

:: Workshop IDs:
:: EpochExperimental = 455221958
:: Normal Epoch = 421839251
SET WORKSHOPID=455221958

START "" /WAIT "%TOOLSPATH%\Publisher\PublisherCmd.exe" update /id:%WORKSHOPID% /changeNote:%CHANGELOG% /path:"%WORKSHOPPATH%"
