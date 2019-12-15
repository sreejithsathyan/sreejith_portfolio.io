var http = require('http');
var fs = require('fs');

function handle_incoming_request (req, res) 
{
    console.log("INCOMING REQUEST: " + req.method + " " + req.url);
    load_sensor_data(function(err, readings)
    {
    if (err) 
    { 
       	console.log("Couldn't read file");
    }
    console.log(readings);
    readings = readings.split(', ');
    var i 
    weather_data = []
    for (i = 0;i < readings.length; i = i+5)
  		{ 
  			weather_data.push({
			"temperature" : readings[i+0],
			"humidity" : readings[1+i],
			"windSpeed" : readings[2+i],
			"time" : readings[3+i],
			"location" : readings[4+i]
		})
  		}
	res.writeHead(200, { "Content-Type" : "application/json" });
	res.end(JSON.stringify(weather_data));
   });
}
function load_sensor_data(callback) 
{
   	fs.readFile("sensorlog.txt",'utf8',function (err, readings) 
   	{
   		if (err) 
   		{
		callback(err);
		return;
		}
		callback(null, readings);
	});
}
var s = http.createServer(handle_incoming_request);
s.listen(8080);