$(document).ready(function(e){
  console.log("Doc rdy m8 :-)");

  $("#entradaArchivo_clicker").click(function(ev){
    $("#archivo_in").trigger("click")
    $(this).hide()
    $("#entradaArchivo_submiter").show()

    //LINEA SOLO PARA VER SI FUNCIONA LA BARRA DE CARGA
    $("#progressbar").show()
  })

  $("#entradaArchivo_submiter").click(function(ev){
    ev.preventDefault();
    //console.log("agregar la parte para mandar html al cpp");
    /*aquí va la parte para mandar el archivo al back*/
    var fiData = $("#archivo_in").prop('files')[0];
    var nfile = fiData.name

    $.ajax({
        type: 'POST',
        // make sure you respect the same origin policy with this url:
        // http://en.wikipedia.org/wiki/Same_origin_policy
        url: "http://10.100.66.112:8000",
        data: {nFile:nfile},
        success: function(msg){
            alert('wow' + msg);
        }
    });
  })

});

//Barra de carga
$( "#progressbar" ).progressbar({
  value: false
});
