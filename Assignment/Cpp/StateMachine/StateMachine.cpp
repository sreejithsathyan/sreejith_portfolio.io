// C++ code for demonstarte FinateStateAutomata for Weather calculation.
// code author :: Sreejith Sathyan B001308332
// required header files 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <iostream>
#include <random>
#include <windows.h>
#include <ctime>
#include <fstream>

// intilizing varibles and arry for corresponding function
using namespace std;
char counter_str[10];
int Temperature_Data[60];
int Humidity_Data[60];
int Windspeed_Data[60];
float Temperature_average = 0.0;
float Humidity_average = 0.0;
float Windspeed_average = 0.0;
string Time;
string Location;
int sensorlog, activeStates;


// declaration of class weather
class Weather
{
public:
	void Sensor();
	void Process();
	void Idel();
};

enum states
{
	ST_Idel= 1,
	ST_Sensing= 2,
	ST_Processing= 3,
};

// Method Sensor definition outside the class
// Code generate random numers for temeperature data.
void Weather::Sensor()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> random_data(1, 20);
	std::uniform_int_distribution<> random_data1(10, 75);
	std::uniform_int_distribution<> random_data2(1, 15);
	cout << "Sensing..." << " :";
	for (int n = 0; n < 50; ++n)
	{
		Temperature_Data[n] = random_data(eng); // Storing temperature data to array.
		Humidity_Data[n] = random_data1(eng); // Storing temperature data to array.
		Windspeed_Data[n] = random_data2(eng); // Storing temperature data to array.
		cout << "#";
		Sleep(200);
	}
	activeStates = 3;
	cout << "\n" << "Sensing --> Processing" << "\n";
}

// Method process definition outside the class
void Weather::Process()
{
	cout << "\n" << "Processing Weather Data" << " : ";
	for (int i = 0; i < 60; i++)
	{
		Temperature_average = Temperature_average + Temperature_Data[i];
		Humidity_average = Humidity_average + Humidity_Data[i];
		Windspeed_average = Windspeed_average + Windspeed_Data[i];
		cout << "#";
		Sleep(200);
	}
	Temperature_average = Temperature_average / 60;
	Humidity_average = lround(Humidity_average / 60);
	Windspeed_average = lround(Windspeed_average / 60);
	time_t my_time = time(NULL);
	sprintf(counter_str, ctime(&my_time));

	Time = counter_str;
	Time.erase(Time.length() - 1);
	Location = "Blanchardstown";

	// write data to sesorlog.txt 
	std::ofstream out("sensorlog.txt", std::ios_base::app);
	out << Temperature_average << ", " << Humidity_average << ", " << Windspeed_average << ", " << Location << ", " << Time << ",";

	// print data on console
	cout << "\n" << "Current  Temperature : " << Temperature_average << "\n";
	cout << "Current  Humidity : " << Humidity_average << "\n";
	cout << "Current  Windspeed : " << Windspeed_average << "\n";
	cout << "Current  Location : " << Location << "\n";
	cout << "Current  Time : " << Time;
	activeStates = 1;
	cout << "\n" << "Processing -> idel" << "\n";
}
// Method Idel definition outside the class
void Weather::Idel()
{
	cout << "\n" << "Idel State for 5000Ms" << "\n";
	for (int i = 0;i<50;i++)
		Sleep(100);
	activeStates = 2;
	cout << "\n" << "Idel --> Sensing" << "\n";
}

int main()
{
	activeStates = 1;
	Weather myObj;
	while (1)
	{
		switch (activeStates)
		{
		case ST_Idel:
			myObj.Idel();
		case ST_Sensing:
			myObj.Sensor();
		case ST_Processing:
			myObj.Process();
		}
	}
}