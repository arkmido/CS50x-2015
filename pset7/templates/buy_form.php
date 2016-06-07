<?php require("menunav.php"); ?>
<div class="sell">
	<fieldset>
		<form action="buy.php" method="post">
			<div class="form-group">
				<input autofocus type="text" name="symbol" placeholder="symbol" size="20" maxlength="20"/>
			</div>
			<div class="form-group">
				<input type="text" name="shares" placeholder="shares" size="20" maxlength="20"/>
			</div>
			<div class="form-group">
				<button class="btn btn-default">Buy Stock</button>
			</div>	
		</form>
	</fieldset>
</div>