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
	temp_data.append(data.get("temperature")) 
	time_data.append(data.get("time")) 

fig,ax=plt.subplots()
ax.plot(time_data,temp_data,label='Weather forecast')
y = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
ax.set_ylabel('°C')
ax.set_title('Temperature')
ax.legend()
fig.autofmt_xdate()
plt.show()

