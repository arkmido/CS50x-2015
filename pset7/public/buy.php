<?php
	require("../includes/config.php");

	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$stock = lookup($_POST["symbol"]);

		if(empty($_POST["symbol"]) || empty($_POST["shares"]))
			apologize("You must specify stock to buy and number of shares.");
		else if(preg_match("/^\d+$/", $_POST["shares"]) != 1)
			apologize("Invalid number of shares.");
		else if($stock == false)
			apologize("Cannot find symbol.");
		else
		{
			$stock_price = $stock["price"] * $_POST["shares"];

			$row = query("SELECT cash FROM users WHERE id=?", $_SESSION["id"]);
			if($row[0]["cash"] >= $stock_price)
			{
				// upcase symbol
				$_POST["symbol"] = strtoupper($_POST["symbol"]);

				// updates portfolio
				query("INSERT INTO portfolio (id, symbol, shares)
					VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)"
					,$_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
				
				// updates user's cash
				query("UPDATE users SET cash = cash - ? WHERE id=?", $stock_price, $_SESSION["id"]);

				// log into history
				query("INSERT INTO history (id, transaction, symbol, shares, price)
					VALUES(?,?,?,?,?)", $_SESSION["id"], "BUY", $_POST["symbol"], $_POST["shares"], $stock_price);
				
				header("Location: /");
			}
			else
			{
				apologize("You have insufficient cash.");
			}
			
		}
	}
	else if($_SERVER["REQUEST_METHOD"] == "GET")
		render("buy_form.php", ["title" => "Buy Stocks"]);
?>