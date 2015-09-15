private["_hours"];
_hours = floor(servertime/60/60);

hintSilent parseText format ["
	<t size='1.25' font='puristaLight' align='center'>Welcome to Epoch Alpha</t><br/>
	<t size='1.18' font='puristaLight' align='center'>Current Version: %22</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Temp: </t><t size='1.15' font='puristaLight' align='right'>%1</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Blood Pressure: </t><t size='1.15' font='puristaLight' align='right'>%2</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Hunger: </t><t size='1.15' font='puristaLight' align='right'>%3</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Thirst: </t><t size='1.15' font='puristaLight' align='right'>%4</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Energy: </t><t size='1.15' font='puristaLight' align='right'>%5</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Wet: </t><t size='1.15' font='puristaLight' align='right'>%6</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Soiled: </t><t size='1.15' font='puristaLight' align='right'>%7</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Immunity: </t><t size='1.15' font='puristaLight' align='right'>%8</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Toxicity: </t><t size='1.15' font='puristaLight' align='right'>%9</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Stamina: </t><t size='1.15' font='puristaLight' align='right'>%10</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Fatigue: </t><t size='1.15' font='puristaLight' align='right'>%11</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Damage: </t><t size='1.15' font='puristaLight' align='right'>%12</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Bleeding: </t><t size='1.15' font='puristaLight' align='right'>%13</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Bleed Time: </t><t size='1.15' font='puristaLight' align='right'>%14</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Oxygen: </t><t size='1.15' font='puristaLight' align='right'>%15</t><br/>
	<br/>
	<t size='1.15' font='puristaLight' align='left'>Air Temp: </t><t size='1.15' font='puristaLight' align='right'>%16</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Water Temp: </t><t size='1.15' font='puristaLight' align='right'>%17</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Rain: </t><t size='1.15' font='puristaLight' align='right'>%18</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Overcast: </t><t size='1.15' font='puristaLight' align='right'>%19</t><br/>
	<br/>
	<t size='1.15' font='puristaLight' align='left'>Crypto: </t><t size='1.15' font='puristaLight' align='right'>%20</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Hours Alive: </t><t size='1.15' font='puristaLight' align='right'>%21</t><br/>
	<t size='1.15' font='puristaLight' align='left'>FPS: </t><t size='1.15' font='puristaLight' align='right'>%23</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Server uptime: </t><t size='1.15' font='puristaLight' align='right'>%24h %25m</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Server FPS: </t><t size='1.15' font='puristaLight' align='right'>%26</t><br/>",
	EPOCH_playerTemp,
	EPOCH_playerBloodP,
	EPOCH_playerHunger,
	EPOCH_playerThirst,
	EPOCH_playerEnergy,
	EPOCH_playerWet,
	EPOCH_playerSoiled,
	EPOCH_playerImmunity,
	EPOCH_playerToxicity,
	EPOCH_playerStamina,
	(getFatigue player),
	(damage player),
	(isBleeding player),
	(getBleedingRemaining player),
	(getOxygenRemaining player),
	EPOCH_CURRENT_WEATHER,
	(EPOCH_CURRENT_WEATHER/2),
	rain,
	overcast,
	EPOCH_playerCrypto,
	round(EPOCH_playerAliveTime/360)/10,
	getText(configFile >> "CfgMods" >> "Epoch" >> "version"),
	round diag_fps,
	_hours,
	round((serverTime/60)-(_hours*60)),
	if (typeName EPOCH_diag_fps == "SCALAR") then [{EPOCH_diag_fps},{"MANIPULATED"}]
];

