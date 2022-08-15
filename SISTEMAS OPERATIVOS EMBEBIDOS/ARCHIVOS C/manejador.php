<!DOCTYPE html>
<html lang="en">
<!--
   
-->

<head>
<meta charset="utf-8" />
<title>Prueba de PHP</title>
</head>

<body>
	<?php 
		$nombre=filter_input(INPUT_GET,"usuario");
		echo '<p>Hola '.$nombre.'!</p>'; 
	?>
</body>

</html>
