<?php
/*
    Example PHP code - Case-insensitive search for player Name returns UID's.
    Requires: PHP5 and https://github.com/phpredis/phpredis installed
    EpochMod.com by [VB]AWOL
*/

$search = 'Bob Jones';

$redis = new Redis();
$redis->pconnect(122.99.21.122, 6379, 2.5, "Server1");
$redis->auth("yourlongasspasswordhere");
    
$playerNames = $redis->keys('PlayerData:*');

// print all UID's matching player name
foreach ($playerNames as $key => $value) {
    $data =  $redis->get($value);
    if (stripos($data, $search) !== false) {
        $key = explode(":", $value);
        echo "<p>" . $key[1] . "</p>" ;
    }
}

?>
