<?php
	require("../includes/config.php");

	$log = query("SELECT * FROM history WHERE id=?", $_SESSION["id"]);
	
	$cash = query("SELECT cash FROM users WHERE id=?", $_SESSION["id"]);
	
	render("history_form.php", ["title" => "History", "log" => $log, "cash" => ($cash[0]["cash"])]);
?>