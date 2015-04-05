<?php
/*
    Example PHP code - Returns list of online player names with position data.
    Requires: PHP5 and https://github.com/phpredis/phpredis installed
    by [VB]AWOL - EpochMod.com
    
    This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
    http://creativecommons.org/licenses/by-sa/4.0/
*/

$instance = 'NA123';

$redis = new Redis();
$redis->pconnect(127.0.0.1, 6379, 2.5, "Server1");
$redis->auth("yourlongasspasswordhere");

// get online players UID array
$data = $redis->get('PLAYERS:' . $instance);
$onlineUIDs = json_decode($data);

// loop though online player UID's 
foreach ($onlineUIDs as $key => $UID) {

    // get character data
    $dataRaw = $redis->get('Player:' . $UID);
    $data = json_decode($dataRaw);

    // get player name
    $dataRaw1 = $redis->get('PlayerData:' . $UID);
    $data1 = json_decode($dataRaw1);

    // get position data from character data array
    $x = $data[0][1][0];
    $y = $data[0][1][1];

    // get player name
    $name = $data1[0];

    echo '<p>'. $name.' at '.$x.' '.$y.'</p>';
}

?>
