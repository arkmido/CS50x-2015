<?php require("menunav.php"); ?>
<br>
<div>
	<table class="table table-striped">
		<thead>
			<tr>
				<td colspan="4"><b>Current Cash</b></td>
				<td><b>$<?=number_format($cash, 2, '.', ',')?></b></td>
			</tr>
			<tr>
				<td>Transaction</td>
				<td>Date/Time</td>
				<td>Symbol</td>
				<td>Shares</td>
				<td>Price</td>
			</tr>	
		</thead>
		<tbody>
			<?php
				foreach($log as $l)
				{
					print("<tr>");
					print("<td>".$l["transaction"]."</td>");
					print("<td>".date('d/m/y, g:i A',strtotime($l["date_time"]))."</td>");
					print("<td>".$l["symbol"]."</td>");
					print("<td>".$l["shares"]."</td>");
					print("<td>$".number_format($l["price"], 2, '.', ',')."</td>");
					print("</tr>");
				}
			?>
		</tbody>
	</table>
</div>