// C++ code for demonstarte FinateStateAutomata for Weather calculation.
// code author :: Sreejith Sathyan B001308332
#include <iostream>
#include <random>
#include <windows.h>
#include <ctime>
#include <fstream>

using namespace std;
int Temperature_Data[60];
int Humidity_Data[60];
int Windspeed_Data[60];
float Temperature_average = 0.0;
float Humidity_average = 0.0;
float Windspeed_average = 0.0;
string Time;
string Location;
int sensorlog;


class Weather 
{ 
	public:  
		void Sensor();
		void Process();
		void Idel();
};

// Method Sensor definition outside the class
void Weather::Sensor()
{	// Code generate random numers for temeperature data.
	std::random_device rd; 
	std::mt19937 eng(rd()); 
	std::uniform_int_distribution<> random_data(1, 20);
	std::uniform_int_distribution<> random_data1(10, 75);
	std::uniform_int_distribution<> random_data2(1, 15);
	cout << "Sensing..." << " :";
	for (int numb = 0; numb < 50; ++n)
	{
		Temperature_Data[numb] = random_data(eng); // Storing temperature data to array.
		Humidity_Data[nnumb = random_data1(eng); // Storing temperature data to array.
		Windspeed_Data[numb] = random_data2(eng); // Storing temperature data to array.
		cout << "#";
		Sleep(50);
	}
}
// Method process definition outside the class
void Weather::Process()
{
	for (int i = 0; i < 60; i++)
	{
		Temperature_average = Temperature_average + Temperature_Data[i];
		Humidity_average = Humidity_average + Humidity_Data[i];
		Windspeed_average = Windspeed_average + Windspeed_Data[i];
	}

	Temperature_average = Temperature_average / 60;
	Humidity_average = lround(Humidity_average / 60);
	Windspeed_average = lround(Windspeed_average / 60);
	Time = "Time";
	Location = "Blanchardstown";

	std::ofstream out("sensorlog.txt", std::ios_base::app);
	out << Temperature_average <<", "<< Humidity_average<<", "<< Windspeed_average<<", "<< Time<<", "<< Location<<", ";
	out.close();


	//time_t now = time(0);
	//tm* ltm = localtime(&now);
	
	cout <<"\n"<< "Processing Weather Data....." << "\n\n";
	cout << "Current  Temperature : " << Temperature_average << "\n";
	cout << "Current  Humidity : " << Humidity_average << "\n";
	cout << "Current  Windspeed : " << Windspeed_average << "\n";
	cout << "Current  Time : " << Time << "\n";
	//cout << "Time: " << 1 + ltm->tm_hour << ":";
	//cout << 1 + ltm->tm_min << ":";
	//cout << 1 + ltm->tm_sec << endl;
	cout << "Current  Location : " << Location << "\n";

}
// Method Idel definition outside the class
void Weather::Idel()
{
	cout << "Idel State for 5000Ms" << "\n";
	Sleep(5000);
}

int main() 
{
	while (1)
	{
		Weather myObj;   // Create an object of Weather
		myObj.Sensor();  
		myObj.Process();
		myObj.Idel();
	}
}