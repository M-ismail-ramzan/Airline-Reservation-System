#include <iostream>
#include <string>
#include "./Flight_Schedule.h"
using namespace std;

void show_flights(string city){
	Flights_Schedule obj;
	obj.set_Flights_info();
	obj.get_details_from_file(city);
}