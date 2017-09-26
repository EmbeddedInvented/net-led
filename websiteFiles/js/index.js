window.onload = colorBack
        function colorBack() {
        colorURL = "https://api.spark.io/v1/devices/<***Insert Device Id Here***>/color/?access_token=<***Insert Access token here***>";
        $.getJSON(colorURL, function(jsonColor,online) {
        	var elem = document.getElementById('col');
        	$("span1").html(jsonColor.result);
    		if(jsonColor.result == "party1")
    		{
    			elem.style.backgroundImage = "url('https://cdn.pixabay.com/photo/2016/05/26/22/49/rainbow-1418706_960_720.png')";//URL for rainbow imge for "party"
    		}
    		else
    		{
    			elem.style.backgroundImage = "none";    	
    			elem.style.backgroundColor = jsonColor.result;
    		}
    	$("span").html("<b style=\"color:#00FF00\">" + online + "</b>");
        });
    }

var postURL = "https://api.particle.io/v1/devices/<***Insert Device Id Here***>/led?access_token=<***Insert Access token here***>";
 
    $(document).ready(function(){
    $("#red").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#FF0000"})
    });    
    $("#green").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#00FF00"})
    });
    $("#blue").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#0000FF"})
    });
    $("#orange").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#FF8000"})
    });
    $("#yellow").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#FFFF00"})
    });
    $("#fuschia").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#FF00FF"})
    });
    $("#aqua").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#00FFFF"})
    });
    $("#white").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "#FFFFFF"})
    });
    $("#off").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "off"})
    });
    $("#party").click(function(){
    	$("span").html("<b style=\"color:#FFFF00\"> Sending </b>")
    	setTimeout(colorBack, 1500);
        $.post(postURL, { color: "party"})
    });

    });