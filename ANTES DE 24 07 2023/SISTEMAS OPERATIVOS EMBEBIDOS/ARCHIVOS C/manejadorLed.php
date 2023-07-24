<!DOCTYPE html>
<?php
	$minutos=filter_input(INPUT_GET,"cronometro");
	shell_exec("/usr/local/bin/uartTXT ".$minutos);
	print_r($_REQUEST);
	
?>
<html lang="en">
<!--
-->

<head>
<meta charset="utf-8" />
<title>Formulario para controlar un LED</title>
</head>
<body>
	<form action="manejadorLed.php" method="GET">
		<?php
		if($encendido=='on'){
			echo 'LED: <input name="encendido" type="number" checked="on" />';
		}else{
			echo "Los datos han sido cargados";
		}
		?>
		<input type="submit" value="Enviar" />
	</form>
</body>

</html>
