@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server

::(Full client\server package)
SET ARMAAPPID=107410

::(Dedicated server package)
::SET ARMAAPPID=233780

::(Development version)
::SET ARMAAPPID=107410 -beta development

:: more info https://community.bistudio.com/wiki/Arma_3_Dedicated_Server

steamcmd.exe +login %STEAMUN% %STEAMPW% +force_install_dir "%ARMASVRPATH%" "+app_update %ARMAAPPID%" validate +quit
