<?php
	require("../includes/config.php");

	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$stock = lookup($_POST["symbol"]);
		$p = $stock["price"];

		if($stock == false)
			apologize("Cannot find symbol.");
		
		render("quote_result.php", ["title" => "Quotes", "name" => $stock["name"], 
		"symbol" => $stock["symbol"], "price" => $stock["price"]]);
	}
	else if($_SERVER["REQUEST_METHOD"] == "GET")
		render("quote_form.php", ["title" => "Quotes"]);
?>