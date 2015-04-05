<?php
/*
    Example PHP code - Returns list of online player names.
    Requires: PHP5 and https://github.com/phpredis/phpredis installed
    by [VB]AWOL - EpochMod.com
    
    This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
    http://creativecommons.org/licenses/by-sa/4.0/
*/

$instance = 'NA123'; // change this to match your servers instanceID

$redis = new Redis();
$redis->pconnect(127.0.0.1, 6379, 2.5, "Server1");
$redis->auth("yourlongasspasswordhere");
    
// get online players UID array
$data = $redis->get('PLAYERS:' . $instance);
$onlineUIDs = json_decode($data);

// loop though online player UID's 
foreach ($onlineUIDs as $key => $UID) {

    // get player name
    $dataRaw = $redis->get('PlayerData:' . $UID);
    $data = json_decode($dataRaw);

    // print player name
    echo '<p>'. $data[0].'</p>';
}

?>
