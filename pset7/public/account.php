<?php
	require("../includes/config.php");

	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		if(empty($_POST["oldpass"]) || 
			empty($_POST["newpass"]) || empty($_POST["confirm"]))
		{
			apologize("Please complete all fields.");
		}
		else if($_POST["confirm"] != $_POST["newpass"])
		{
			apologize("New password and confirmation mismatched.");
		}
		else if($_POST["oldpass"] == $_POST["newpass"] ||
			$_POST["oldpass"] == $_POST["confirm"])
		{
			apologize("Choose a different password.");
		}

		$row = query("SELECT hash FROM users WHERE id=?", $_SESSION["id"]);

		if(crypt($_POST["oldpass"], $row[0]["hash"]) != $row[0]["hash"])
		{
			apologize("Invalid password.");
		}
		$row = query("UPDATE users SET hash = ? WHERE id=?", crypt($_POST["newpass"],$row[0]["hash"]), $_SESSION["id"]);
		if($row === false)
			apologize("Something went wrong.");
		else
		{
			render("pass_form.php", ["title" => "Account", "pass" => "changed"]);
		}
	}
	else if($_SERVER["REQUEST_METHOD"] == "GET")
	{
		render("pass_form.php", ["title" => "Account"]);
	}
?>