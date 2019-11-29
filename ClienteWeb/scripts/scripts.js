$(document).ready(function(e){
  console.log("Doc rdy m8 :-)");

  $("#entradaArchivo_clicker").click(function(ev){
    $("#archivo_in").trigger("click")
    $(this).hide()
    $("#entradaArchivo_submiter").show()
  })

  $("#entradaArchivo_submiter").click(function(ev){
    ev.preventDefault();
    console.log("agregar la parte para mandar html al cpp");
    /*aquí va la parte para mandar el archivo al back*/
    var fiData = $("#archivo_in").prop('files')[0];
    var nfile = fiData.name
    console.log("Nombre de archivo: ".concat(nfile));
    //var foData = new FormData();
    //foData.append(fiData)

    $.ajax({  url : 'scripts/run.php',
              data: {nFile:nfile} }).done( function(data){ console.log(data); });
  })

});
