<?php
/**
 * @brief		Public bootstrap
 * @author		Aaron Clark
 * @copyright	(c) 2016 Epoch Mod
 * @license		http://creativecommons.org/licenses/by-sa/4.0/
 * @package		Parse SQM v12 to version 51
 * @since		
 * @version		
 */
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

class Mission {

	var $addOns;
	var $addOnsAuto;
	var $randomSeed;
	var $intel;
	var $groups;
	var $markers;
   	
	function Mission(
		$addOns = array(),
		$addOnsAuto = array (
			"A3_epoch_config",
			"cup_zargabad_config"
		),
		$randomSeed=12032465,
		$intel = array(	
			'briefingName'=>'Epoch Mod',
			'timeOfChanges'=>28800,
			'startWeather'=>0,
			'startWind'=>0,
			'startWaves'=>0,
			'forecastWeather'=>0,
			'forecastWind'=>0,
			'forecastWaves'=>0,
			'forecastLightnings'=>1.0,
			'year'=>2035,
			'month'=>6,
			'day'=>24,
			'hour'=>12,
			'minute'=>0,
			'startFogDecay'=>0.013,
			'forecastFogDecay'=>0.013
		),
		$playerCount = 100,
		$groups = array (
			'Item0' => array (
				'side'=>'CIV',
				'Vehicles' => array (
					'Item0' => array (
						'position'=> array(4331.02,0,148.62354),
					)
				)
			)
		),
		$markers = array (
			
			'Item0' => array (
				'position' => array (4135.0137,0,4039.3584),
				'name'=>"center",
				'type'=>"Empty",
			),
			'Item1' => array (
				'position' => array (4331.02,0,148.62354),
				'name'=>"respawn_east",
				'type'=>"Empty",
			),
			'Item2' => array (
				'position' => array (4331.02,0,148.62354),
				'name'=>"respawn_west",
				'type'=>"Empty",
			),
			'Item3' => array (
				'position' => array (3257.1497,0,1079.2324),
				'name'=>"south",
				'type'=>"Empty",
			),
			'Item4' => array (
				'position' => array (3154.1616,0,5169.5229),
				'name'=>"east",
				'type'=>"Empty",
			)

		)
    ) 
	{
	   $this->addOns = $addOns;
	   $this->addOnsAuto = $addOnsAuto;
	   $this->randomSeed = $randomSeed;
	   $this->intel = $intel;
	   $this->playerCount = $playerCount;
	   $this->groups = $groups;
	   $this->markers = $markers;
	}




} // end of class Mission




?>
<pre>
<?php

// utility functions

function print_vars($obj) 
{
	foreach (get_object_vars($obj) as $prop => $val) {
	    if (!is_array($val)) {
	    	echo "\t$prop = $val\n";	
	    } else {
	    	echo "\t$prop = \n";	
			print_r($val);
	    }
	}
}

function print_methods($obj) 
	{
	$arr = get_class_methods(get_class($obj));
	foreach ($arr as $method) {
	    echo "\tfunction $method()\n";
	}
}

function class_parentage($obj, $class) 
{
	if (is_subclass_of($GLOBALS[$obj], $class)) {
	    echo "Object $obj belongs to class " . get_class($GLOBALS[$obj]);
	    echo ", a subclass of $class\n";
	} else {
	    echo "Object $obj does not belong to a subclass of $class\n";
	}
}

// instantiate 2 objects
$mission = new Mission();

// print out information about objects
// echo "CLASS " . get_class($mission) . "\n";

// show mission properties
 //echo "\nmission: Properties\n";
 //print_vars($mission);

echo "version=51;
class EditorData
{
	moveGridStep=1;
	angleGridStep=0.2617994;
	scaleGridStep=1;
	autoGroupingDist=10;
	toggles=1;
	class ItemIDProvider
	{
		nextID=2;
	};
	class Camera
	{
		pos[]={7542.4932,93.791428,15492.986};
		dir[]={-0.8989169,-0.17364819,-0.40223712};
		up[]={-0.15850332,0.98480779,-0.070925266};
		aside[]={-0.40844229,0,0.91278416};
	};
};
binarizationWanted=0;
";



echo "addons[]=
{
";
foreach ($mission->addOnsAuto as $key => $value) {
    if (is_string($value)) {
		echo "	\"$value\",\n";
    } else {
    	echo "	$value,\n";
    }
    	
}
echo "};\n";


echo "randomSeed=$mission->randomSeed;\n";
echo "class ScenarioData
{
	author=\"[VB]AWOL\";
};\n";



echo "class Mission
{
	class Intel
	{
";
foreach ($mission->intel as $key => $value) {
    if (is_string($value)) {
		echo "		$key=\"$value\";\n";
    } else {
    	echo "		$key=$value;\n";
    }
    	
}
echo "	};\n";

$EntitiesCounter = 0;

echo "	class Entities
	{
";
echo "		items=". (count($mission->markers) + $mission->playerCount) .";\n";

foreach ($mission->markers as $key => $value) {
	
	$position = implode(",", $value["position"]);
    echo "		class Item".$EntitiesCounter."
		{
			dataType=\"Marker\";
			position[]={".$position."};
			name=\"".$value["name"]."\";
			type=\"".$value["type"]."\";
			id=".$EntitiesCounter.";
		};\n";
	$EntitiesCounter++;
    	
}

for ($x = count($mission->markers); $x <= ($mission->playerCount+count($mission->markers)); $x++) {

	foreach ($mission->groups as $key => $value) {
		
		$position = implode(",", $value["Vehicles"]["Item0"]["position"]);
	    echo "		class Item".$x."
		{
			dataType=\"Group\";
			side=\"Civilian\";
			class Entities
			{
				items=1;
				class Item0
				{
					dataType=\"Object\";
					class PositionInfo
					{
						position[]={".$position."};
						angles[]={0,4.7169838,0};
					};
					side=\"Civilian\";
					flags=3;
					class Attributes
					{
						isPlayable=1;
					};
					id=".($EntitiesCounter+1).";
					type=\"VirtualMan_EPOCH\";
				};
			};
			class Attributes
			{
			};
			id=".$EntitiesCounter.";
		};\n";
		$EntitiesCounter++;
		$EntitiesCounter++;
	    	
	}
} 



// Entities end
echo "	};\n";




// final 
echo "};\n";

?>
</pre>

<?php

echo '
</body>
</html>
';