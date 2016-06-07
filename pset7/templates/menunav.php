<?php
	$name = query("SELECT username FROM users WHERE id=?", $_SESSION["id"]);
?>
<div id="menu">
    <ul>
        <li>P<a href="/">ortfolio</a></li>
        <li>Q<a href="quote.php">uotes</a></li>
        <li>B<a href="buy.php">uy</a></li>
        <li>S<a href="sell.php">ell</a></li>
        <li>H<a href="history.php">istory</a></li>
    </ul>
</div> 
<div class="btn-group">
	<button type="button" class="btn btn-success dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
		<?=strtoupper($name[0]["username"])?> <span class="caret"></span>
	</button>
	<ul class="dropdown-menu">
		<li><a href="account.php">Change Password</a></li>
		<li><a href="logout.php">Log out</a></li>
    </ul>
</div>
<br/>