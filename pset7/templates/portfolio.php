<?php require("menunav.php"); ?>
<br/>
<div id="tbl">
	<table class="table table-striped">
		<thead>
			<tr>
				<td colspan="4"><b>Current Cash</b></td>
				<td><b>$<?=number_format($cash[0]["cash"], 2, '.', ',')?></b></td>
			</tr>
			<tr>
				<td>Symbol</td>
				<td>Name</td>
				<td>Shares</td>
				<td>Price</td>
				<td>TOTAL</td>
			</tr>
		</thead>
		<tbody>
			<?php
				foreach ($position as $pos) {
					print("<tr>");
					print("<td>&nbsp;" . $pos["symbol"] . "</td>");
					print("<td>&nbsp;" . $pos["name"] . "</td>");
					print("<td>&nbsp;" . $pos["shares"] . "</td>");
					print("<td>&nbsp;$" . number_format($pos["price"], 2, '.', ',') . "</td>");
					print("<td>&nbsp;$" . number_format($pos["total"], 2, '.', ',') . "</td>");
					print("</tr>");
				}
			?>
		</tbody>
	</table>
</div>