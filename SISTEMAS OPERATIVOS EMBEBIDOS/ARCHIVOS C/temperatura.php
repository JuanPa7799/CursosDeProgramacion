<!DOCTYPE html>
<?php
	$temperatura=shell_exec("/usr/local/bin/uartTemp");
?>

<html lang="en">
<!--
   
-->

<head>
<meta charset="utf-8" />
<title>Prueba de PHP</title>
</head>

<body>
	<?php 
		echo '<p>La temperatura es de '.$temperatura.'°</p>'; 
	?>
</body>

</html>
