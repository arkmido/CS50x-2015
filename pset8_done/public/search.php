<?php

    require(__DIR__ . "../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // split entry by commas and spaces
    $entry = preg_split("/[\s,\+]+/", $_GET["geo"]);

    // removes special characters
    $keywords = [];
    foreach ($entry as $str) {
    	array_push($keywords, preg_replace('/[^A-Za-z0-9\-]/', '', $str));
    }

    // initial query string
    $query = "SELECT * FROM places WHERE ";

    // Build query string
    $ctr = 0;
    foreach ($keywords as $keys) {

    	if(is_numeric($keys)) // postal_code, admin_code2
			$query .= "(postal_code LIKE '%". htmlspecialchars($keys) . "%' OR admin_code2 LIKE '%" . htmlspecialchars($keys) . "%')";
		else // country_code,  admin_code1(2chars) OR place_name, admin_name1, admin_name2
			$query .= strlen($keys) <= 2 ? "(admin_code1 LIKE '%".htmlspecialchars($keys)."%' OR country_code LIKE'%".htmlspecialchars($keys)."%')" : 
			"((place_name LIKE '%".htmlspecialchars($keys)."%' OR admin_name1 LIKE '%".htmlspecialchars($keys)."%') 
				OR admin_name2 LIKE '%".htmlspecialchars($keys)."%')";
		
		// continue building by concatenating 'AND' to last build
		if($ctr < (count($keywords)-1))
		{
			$query .= " AND ";
			$ctr++;
		}
		else
			break;
    }

    // TODO: search database for places matching $_GET["geo"]
    $places = query($query);
    
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
