<?php
  $filename = $_GET['nFile'];           //Obtener de JS el nombre del cliente
  $fil_def = escapeshellarg($filename); //Ajustar cadena para ser compatible en un shell

  $cmd = "./prueba $fil_def";           //Concatenar argumento a un comando sh

  var_dump($fil_def);                   //Mostrar en consola web argumento
  var_dump($cmd);                       //Mostrar en consola web comando

  $salida = shell_exec( "(cd ../../CarpetaPruebas; $cmd)" ); //Retorno del comando shell

  var_dump($salida);                    //Mostrar en consola web salida
?>
