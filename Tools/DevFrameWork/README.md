Epoch Developer Libraries (Framework)
=====
http://epochmod.com

## This guide is WIP

These tools are for developers only, please do not use on public servers, local development servers only!

Technically you can simply copy/paste existing files into your Arma root and forget about it, unless you intend to use these tools for its intended purpose - as a development framework

Don't forget to load the @mod on client

Server config:

Make sure -filepatching is enabled

##### .bat file example
```
@echo off
start "arma3" arma3server.exe autoInit -filepatching -mod=@EpochExperimental; -serverMod=@EpochHive; -port=2302 -config=c:\a3server\sc\server.cfg -cfg=C:\A3Server\sc\basic.cfg -profiles=sc -name=sc
```

* server.cfg
* verifySignatures   	= 0;
* BattlEye            = 0;
* allowedFilePatching = 2;
* // WHITELIST FILE TYPES
* allowedLoadFileExtensions[] = {:};
* allowedPreprocessFileExtensions[] = {"sqf"};
* allowedHTMLLoadExtensions[] = {"html"};


# Advanced:


Create your own sandbox using mine as a template, this will save you headache on future tool updates.
I will provide a clean template later.

To create your own sandbox:
* Copy rmx_sanbox folder and rename it
* update .bat file to support your new folder
* update $PBOPREFIX$
* delete "epoch" folder
* clean up config.cpp (see class A3E)
* cleanup sandbox.sqf
* you can either clean up variables.sqf, rename or delete it. It is used for F3 menu - to save permament code snippets :)

Config.cpp
```
preInit = 1; //function run as soon as missionNamespace is created
postInit = 1; //function is run after everything else is loaded
recompile = 1; //function is not finalized and can be recompiled live using rmx_fnc_recompile or F3 menu (auto populated)
```

### Tools:

##### F2 - Debug console
you need an include in each of your scritps for it to work
```
#include <\x\Addons\rmx_init\defines.inc>
```

to call debug console events you need to call infos, warnings or critical from your scripts. Examples:
```
"this is info" info;
(2+2) warning;
(call _myfnc) critical;
```

#### F3 - Quick launch

Edit variables.sqf

Quick launch depends on rmx_var_quickFnc_items array, that's all there is to it.

You can save code snippets here that you use the most.
```
Syntax: [[RGBA],name,function]
```

#### F4 - variable watcher, see my youtube video

#### F5, F6 etc tools are mostly used for Single player to change weather or post processing effects.


edit .bat file

make sure you also point to includes.txt correctly without spaces

Shit, this documentation will take me a week to compile all the features properly...

License:
=====
Arma Public License Share Alike (APL-SA).
http://www.bistudio.com/community/licenses/arma-public-license-share-alike

Credits:
=====
https://github.com/EpochModTeam/Epoch/blob/release/CREDITS.md
