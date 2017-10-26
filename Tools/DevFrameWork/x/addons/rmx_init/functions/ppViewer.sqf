/*
	Function Name:			rmx_fnc_ppViewer
	Author:					Raimonds Virtoss | Raymix
	Description:			Postprocess viewer
	
	License:				---
*/
private ["_display","_diag"];
disableSerialization;

switch (rmx_var_ppViewerEnabled) do {
	case false: 
	{
		_diag = createDialog "dUI_ppEffects";
		_display = findDisplay 6100;
		
		{rmx_var_ppCatMain set [count rmx_var_ppCatMain,_display displayCtrl _x];}count
		[
			6110,6111, //combo
			6120, //edit
			6130,6130,6130,6130,6130,6130,6130 //buttons
		];
		
		{rmx_var_ppCatCC set [count rmx_var_ppCatCC,_display displayCtrl _x];}count
		[
			6210, //bg
			6220,6221,6222,6223,6224,6225,6250, //txt
			6230,6231,6232,6233,6234,6235,6236,6237,6238,6239,6240,6241,6242,6243,6244, //sliders
			6251 //bool
		];
		
		{rmx_var_ppCatCCV set [count rmx_var_ppCatCCV,_display displayCtrl _x];}count
		[
			6260, //bg
			6270,6271,6272,6273,6274,6275,6276, //txt
			6280,6281,6282,6283,6284,6285,6286 //sliders
		];
		
		{rmx_var_ppCatCA set [count rmx_var_ppCatCA,_display displayCtrl _x];}count
		[
			6310, //bg
			6320,6321,6322, //txt
			6330,6331, //sliders 
			6340 //cb
		];
		
		{rmx_var_ppCatFG set [count rmx_var_ppCatFG,_display displayCtrl _x];}count
		[
			6410, //bg
			6420,6421,6422,6423,6424,6425, //txt
			6430,6431,6432,6433,6434, //sliders
			6440 //cb
		];
		
		{rmx_var_ppCatRB set [count rmx_var_ppCatRB,_display displayCtrl _x];}count
		[
			6510, //bg
			6520,6521,6522,6523, //txt
			6530,6531,6532,6533 //sliders
		];
		
		{rmx_var_ppCatWD set [count rmx_var_ppCatWD,_display displayCtrl _x];}count
		[
			6610, //bg
			6620,6621,6622,6623,6624,6625, //txt
			6630,6631,6632,6633,6634,6635,6636,6637,6638,6639,6640,6641,6642,6643,6644 //sliders
		];
		
		{rmx_var_ppCatDB set [count rmx_var_ppCatDB,_display displayCtrl _x];}count
		[
			6710, //bg
			6720, //txt
			6730 //sliders
		];
		
		{rmx_var_ppCatCI set [count rmx_var_ppCatCI,_display displayCtrl _x];}count
		[
			6810, //bg
			6820,6821,6822, //txt
			6830,6831,6832 //sliders
		];

		"range" call rmx_fnc_ppViewerGetSet; //sets slider ranges
		["load"] call rmx_fnc_ppViewerUpdate;
		"" call rmx_fnc_ppViewerGetSet; //loads default positions and selections
		call rmx_fnc_ppViewerEffects;
		rmx_var_ppViewerEnabled = true;
	};
	case true:
	{
		closeDialog 0;
		rmx_var_ppViewerEnabled = false;
	};
};

true
/*

dUI_ppEffects - IDD 6100

Category:	
			Combo:		Main: 6110	
						Load: 6111
						
			Edit:		6120
			
			Buttons:	Load: 6130
						Save: 6131
						Reset: 6132
						Random: 6133
						Delete: 6134
						RPT: 6135
						Reset ALL: 6136

Color Correction:
			Background:	6210
			
			Text:		Brightness: 6220
						Contrast: 6221
						Offset: 6222
						Blend: 6223
						Colorize1: 6224
						Colorize2: 6225
						Vignette: 6250
						
			Sliders:	Brightness: 6230
						Contrast: 6231
						Offset: 6232
						Blend Red: 6233
						Blend Green: 6234
						Blend Blue: 6235
						Blend Alpha: 6236
						Colorize1 Red: 6237
						Colorize1 Green: 6238
						Colorize1 Blue: 6239
						Colorize1 Alpha: 6240
						Colorize2 Red: 6241
						Colorize2 Green: 6242
						Colorize2 Blue: 6243
						Colorize2 Alpha: 6244
						
			Bool:
						Vignette bool: 6251
						
			Vignette:	Background: 6260
			
				Text: 	Hsize: 6270
						Vsize: 6271
						?: 6272
						Hpos: 6273
						Vpos: 6274
						STR: 6275
						Alpha: 6276
						
				Slider:	Hsize: 6280
						Vsize: 6281
						?: 6282
						Hpos: 6283
						Vpos: 6284
						STR: 6285
						Alpha: 6286

Chromatic aberration
			Background:	6310
			
			Text:		X: 6320
						Y: 6321
						Aspect: 6322
						
			Sliders:	X: 6330
						Y: 6331
			
			Checkbox:	CB: 6340
						
Film grain
			Background:	6410
			
			Text: 		Sharpness: 6420
						Intensity: 6421
						Grain Size: 6422
						Intensityx0: 6423
						Intensityx1: 6424
						Monochromic: 6425
						
			Sliders:	Sharpness: 6430
						Intensity: 6431
						Grain Size: 6432
						Intensityx0: 6433
						Intensityx1: 6434
						
			Checkbox:	Bool: 6440
				
Radial Blur
			Background:	6510
			
			Text:		Relative X: 6520
						Relative Y: 6521
						Centre X: 6522
						Centre Y: 6523
						
			Sliders:	Relative X: 6530
						Relative Y: 6531
						Centre X: 6532
						Centre Y: 6533
	
Water Distortion
			BackGround:	6610
			
			Text:		Bluriness: 6620
						STR Top: 6621
						STR Bot: 6622
						Wave speed: 6623
						Wave amp: 6624
						Phase: 6625
						
			Sliders:	Blur: 6630
						STR Top: 6631
						STR Bot: 6632
						Wave speed 1: 6633 
						Wave speed 2: 6634
						Wave speed 3: 6635
						Wave speed 4: 6636
						Wave amp 1: 6637
						Wave amp 2: 6638
						Wave amp 3: 6639
						Wave amp 4: 6640
						Phase 1: 6641
						Phase 2: 6642
						Phase 3: 6643
						Phase 4: 6644
						
Dynamic blur
			Background:	6710
			
			Text:		6720
			
			Slider:		6730
			
Color inversion
			Background:	6810
			
			Text:		Red: 6820
						Green: 6821
						Blue: 6822
						
			Sliders:	Red: 6830
						Green: 6831
						Blue: 6832
	
*/