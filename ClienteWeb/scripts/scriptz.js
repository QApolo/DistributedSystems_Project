function updateProgress(evt) {
  if (evt.lengthComputable) {
    document.getElementById("output").textContent =
          "Uploaded " + evt.loaded + " of " + evt.total + " bytes";
  }
}
function uploadFile() {
  var file_data = new FormData(document.getElementById('filename'));
  $.ajax({
    url: "/upload",
    type: "POST",
    data: file_data,
    processData: false,
    contentType: false,
    cache: false,
    xhr: function() {
      myXhr = $.ajaxSettings.xhr();
      if(myXhr.upload){
        myXhr.upload.addEventListener('progress',updateProgress, false); // for handling the progress of the upload
      }
      return myXhr;
    },
  }).done(function(data) {
      document.getElementById("output").textContent = "Result: " + data;
  });
  return false;
}

$(document).ready(function(e){
  console.log("Documento listo m7.99...9 :-)");

  $("#entradaArchivo_clicker").click(function(ev){
    $("#archivo_in").trigger("click")
    $(this).hide()
    $("#entradaArchivo_submiter").show()
  })
});
