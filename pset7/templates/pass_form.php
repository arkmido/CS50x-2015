<?php require("menunav.php"); ?>

<?php if (isset($pass)): ?>
    <script>alert('Password Changed!');</script>
<?php endif ?>

<br>
<div class="logreg">
	<fieldset id="changepass">
		<legend>Change Password</legend>
		<form action="account.php" method="post" class="form-horizontal">
			<div class="form-group">
				<input autofocus class="form-control" type="password" name="oldpass" placeholder="Old password"/>
			</div>
			<div class="form-group">
				<input type="password" class="form-control" name="newpass" placeholder="New password"/>
			</div>
			<div class="form-group">
				<input type="password" class="form-control" name="confirm" placeholder="Re-type new password"/>
			</div>
			<div class="form-group">
				<button type="submit" class="btn btn-default">Confirm</button>
			</div>
		</form>
	</fieldset>
</div>
<br>
