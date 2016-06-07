<?php require("menunav.php"); ?>

<div class="sell">
	<fieldset>
		<form action="sell.php" method="post">
			<div class="form-group">
				<select name="symbol" class="form-control">
					<option disabled selected value="">Symbol</option>
					<?php
						foreach ($symbols as $s)
							print("<option value='" . $s["symbol"] . "'>". $s["symbol"] . "</option>");
					?>
				</select>
			</div>
			<div class="form-group">
				<button type="submit" class="btn btn-default">Sell</button>
			</div>	
		</form>
	</fieldset>
</div>
