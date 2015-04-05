<?php
/*
    Example PHP code - Case-insensitive search for player Name returns UID's.
    Requires: PHP5 and https://github.com/phpredis/phpredis installed
    by [VB]AWOL - EpochMod.com
    
    This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
    http://creativecommons.org/licenses/by-sa/4.0/
*/

$search = 'Mr. Jones';

$redis = new Redis();
$redis->pconnect(127.0.0.1, 6379, 2.5, "Server1");
$redis->auth("yourlongasspasswordhere");
    
$playerNames = $redis->keys('PlayerData:*');

// print all UID's matching player name
foreach ($playerNames as $key => $value) {
    $data =  $redis->get($value);
    if (stripos($data, $search) !== false) {
        $key = explode(":", $value);
        echo "<p>" . $key[1] . "</p>" ;
        break; // comment out this line if you want all matches and not just the first.
    }
}

?>
