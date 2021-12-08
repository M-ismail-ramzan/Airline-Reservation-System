#pragma once
#include "./Flights.h"


class Airport {
	// 20 aerolplanes in each city
	// 10 local 5 international everyday from each airport
	// 5 planes can be in airport at a time
	// 20 aerolplanes in each city so logically 10 in each airport at the start
	string airport_name;
	int total_in_airport;
public:
	void set_name(string n) {
		airport_name = n;
	}
	void set_total_airport(int n) {
		total_in_airport = n;
	}
	void display_airport_name() {
		cout  << airport_name  << "\n";
		cout << "Aeroplanes Now: " << total_in_airport << " \n";
	}

};
class City {
	string city_name;
	Airport airports[2];
public:
	City() {
		city_name = "";
		airports[0].set_total_airport(5);
		airports[1].set_total_airport(5);
	}
	//parametrize contructor
	City(string s) {
		city_name = s;
		airports[0].set_total_airport(5);
		airports[1].set_total_airport(5);
	}
	// display outout
	void display_city() {
		cout << "\n" << city_name << "\n";
	}
	// giving names to airport
	void set_airports_name() {
		airports[0].set_name("North");
		airports[1].set_name("South");
	}
	void display_airports_name() {
		airports[0].display_airport_name();
		airports[1].display_airport_name();
	}
};
