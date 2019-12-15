#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway
import matplotlib.pyplot as plt
import urllib.request 
import json
request_url = urllib.request.urlopen('http://localhost:8080/') 
weatherData = json.loads(request_url.read()) 
temp_data = []
time_data = []
for data in weatherData: 
	temp = data.get("temperature")
	temp_data.append(float(temp))
	time_data.append(data.get("time")) 
fig,ax=plt.subplots()
ax.plot(time_data,temp_data,label='Weather forecast')
ax.set_ylabel('°C')
ax.set_xlabel('Time')
ax.set_title('Temperature vs Time')
ax.legend()
fig.autofmt_xdate()
plt.show()