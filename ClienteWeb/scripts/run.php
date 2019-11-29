<?php
  $filename = $_GET['nFile'];
  //$salida =  shell_exec('ls -lart');
  //$salida =  shell_exec('./Cliente '.$filename);

  //$salida = shell_exec('(cd ..; /CarpetaPruebas/prueba)');

  $cmd = "./prueba $filename";

  var_dump($cmd);

  $salida = shell_exec( "(cd ../../CarpetaPruebas; $cmd)" );

  //echo "<pre>$salida</pre>";
  //print_r($salida);
  var_dump($salida);
?>
