<?php
	require("../includes/config.php");

	if($_SERVER["REQUEST_METHOD"] == "GET")
	{
		$rows = query("SELECT * FROM portfolio WHERE id=?", $_SESSION["id"]);
		
		$symbols = [];

		foreach($rows as $row)
		{
			$symbols[] = ["symbol" => $row["symbol"]];
		}
		render("sell_form.php", ["title" => "Sell Stocks", "symbols" => $symbols]);
	}
	else if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$symbol = $_POST["symbol"];
		if($symbol != "")
		{
			$stock = lookup($_POST["symbol"]);
			$share = query("SELECT shares FROM portfolio WHERE id=? AND symbol=?", $_SESSION["id"], $_POST["symbol"]);
			
			$value = $stock["price"] * $share[0]["shares"];
			
			// update user's cash
			query("UPDATE users SET cash = cash + ? WHERE id=?",$value ,$_SESSION["id"]);
			
			// update portfolio
			query("DELETE FROM portfolio WHERE id=? AND symbol =?", $_SESSION["id"], $_POST["symbol"]);

			// log into history
			query("INSERT INTO history (id, transaction, symbol, shares, price)
				VALUES(?,?,?,?,?)", $_SESSION["id"], "SELL", $_POST["symbol"], $share[0]["shares"], $value);

			header("Location: /");
		}
		apologize("You must select a stock to sell.");
	}
	
?>