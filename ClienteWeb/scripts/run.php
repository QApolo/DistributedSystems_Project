<?php
  $filename = $_GET['nFile'];
  $salida =  shell_exec('ls -lart');
  //$salida =  shell_exec('./Cliente '.$filename);
  //echo "<pre>$salida</pre>";
  //var_dump($filename);
  var_dump($salida);
?>
