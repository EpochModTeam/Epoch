private ["_tempVars","_tempVal","_tempIndex","_time"];
_time = if (_this) then [{15},{80}];

_EPOCH_lastSave = missionNamespace getVariable["EPOCH_lastSave", diag_tickTime];

if ((diag_tickTime - _EPOCH_lastSave) >= _time) then {

	missionNamespace setVariable["EPOCH_lastSave", diag_tickTime];

	missionNamespace setVariable ["EPOCH_pushPlayer_PVS",
		[	player,
			[
				missionNamespace getVariable "EPOCH_playerTemp",
				missionNamespace getVariable "EPOCH_playerHunger",
				missionNamespace getVariable "EPOCH_playerThirst",
				missionNamespace getVariable "EPOCH_playerAliveTime",
				missionNamespace getVariable "EPOCH_playerEnergy",
				missionNamespace getVariable "EPOCH_playerWet",
				missionNamespace getVariable "EPOCH_playerSoiled",
				missionNamespace getVariable "EPOCH_playerImmunity",
				missionNamespace getVariable "EPOCH_playerToxicity",
				missionNamespace getVariable "EPOCH_playerStamina",
				missionNamespace getVariable "EPOCH_playerCrypto",
				((getAllHitPointsDamage player) param [2,[]]),
				missionNamespace getVariable "EPOCH_playerBloodP",
				missionNamespace getVariable "EPOCH_playerSpawnArray"
			],
			missionNamespace getVariable "Epoch_personalToken"
		]
	];
	publicVariableServer "EPOCH_pushPlayer_PVS";
};