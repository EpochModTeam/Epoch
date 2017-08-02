rem Adjust path to Pal2PacE.exe below
rem Put this batch inside the same folder as your .paa textures, handy for mass extracting data if you have unRapped your game into P:\ drive
for %%f in (*.paa) do ( "D:\SteamLibrary\steamapps\common\Arma 3 Tools\TexView2\Pal2PacE.exe" "%%~nf.paa" "%%~nf.png" )