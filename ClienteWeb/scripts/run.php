<?php
  $filename = $_GET['nFile'];
  //$salida =  shell_exec('ls -lart');
  //$salida =  shell_exec('./Cliente '.$filename);

  //$salida = shell_exec('(cd ..; /CarpetaPruebas/prueba)');

  $cmd = "./prueba $filename";

  $cmd_def = escapeshellcmd($cmd);

  //var_dump($cmd);
  //var_dump($cmd_def);

  $salida = shell_exec( "(cd ../../CarpetaPruebas; $cmd_def)" );

  //echo "<pre>$salida</pre>";
  //print_r($salida);
  var_dump($salida);
?>
