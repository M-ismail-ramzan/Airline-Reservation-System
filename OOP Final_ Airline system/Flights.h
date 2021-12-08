#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "./Seat.h"
#include "./Flight_Schedule.h"
#include "./Payment.h"
using namespace std;


// Note: Flights are Identified by it's ID and city it belongs to. In other words, id & city is primary key when combined.
class Flights {
	int id;
	int flight_num;
	int total_business_seats;
	int total_economic_seats;
	int business_seat_counter;
	int economic_seat_counter;
	string city;
	Seat *economic_class_seats; // Economic Class
	Seat *business_class_seats; // Business Class
	Flights_Schedule Schedules;
public:
	// This will return All the Information of the Flight
	Flights() {
		id = -1;
		flight_num = 145;
		business_seat_counter = 0;
		economic_seat_counter = 0;
		// Admin can change these values so let's do something ismail!
		total_business_seats = 10;
		total_economic_seats = 50;
		business_class_seats = new Seat[total_business_seats];
		economic_class_seats = new Seat[total_economic_seats];
	}
	// Admin needs to change the Schedule
	void change_schedule_by_admin(string city, int flight_id) {
		Schedules.change_the_schedule_of_flight(city,flight_id);
	}
	// Admin can change the total number of seats remember.
	void change_total_number_of_business_seats(int n) {
		total_business_seats = n;
		// admin changes the number of seats so we need to change dynamic array as well
	}
	void change_total_number_of_economic_seats(int n) {
		total_economic_seats = n;
	}
	// I need to get the schedule of Each Flight.
	void return_full_schedule(string cities,int unique_id) {
		// there should be a function in Schedule that takes an id and city to get all the information
		// of the particular Flight.
		Schedules.get_particular_flight_detail(cities, unique_id);
	}
	// Setter Functions
	void set_city(string n) {
		city = n;
	}
	void set_id(int i) {
		id = i;
	}
	// Getter Functions
	string get_city_flight() {
		return city;
	}
	int get_flight_id() {
		return id;
	}
	// Function which will add the Flight Information in the user
	void add_flight_information_to_user(int user_id,int flight_id,string seat_class,int seat,string city) {
		ofstream obj;
		string temp = to_string(user_id) + ".txt";
		obj.open("./Registered_Users/" + temp,ios::app);
		if (!obj) {
			cout << "\n---Unable to open Registered Files---\n";
		}
		else {
			obj << flight_id << "\n" << seat_class << "\n" << seat << "\n" <<city << "\n";
		}
		obj.close();
	}
	// User wants to Canal Seats
	void cancel_seats(int user_id,string seat_class,int no_of_seats,string city_) {
		
		string tempo = to_string(user_id) + ".txt";
		ofstream out("./Registered_Users/temp.txt");
		ifstream in("./Registered_Users/" + tempo);
		string file_name = "./Registered_Users/temp.txt";
		if (!in || !out) {
			cout << "\nCan't open Files...There is Some issue\n";
		}
		else {
			// copy the first 6 lines and remove others
			string line;
			int line_no = 0;
			while (getline(in, line)) {
				line_no++;
				if (line_no <= 7)
					out << line << "\n";
			}
		}

		out.close();
		in.close();
		string tem = "./Registered_Users/" + tempo;
		remove(tem.c_str());
		 rename(file_name.c_str(), tempo.c_str());

		char *arr= new char[tem.length() + 1];
		strcpy_s(arr,256, tem.c_str());
		char* arr2 = new char[tempo.length() + 1];
		strcpy_s(arr2, 256,tempo.c_str());
		int nas= rename(arr2, arr);
		if (nas == 0) {
			cout << "\n----------------------\nYour Tickets are Successfully Cancelled\nYour Payment will be Transferred to you\n------------------\n soon!";
		}

	}
	int manage_payment() {
		int my_hours = Schedules.get_estimation_time();
		string my_type = Schedules.get_type_flight();
		long price_ticket = Schedules.get_ticket_price();
		//cout << "\n\n\n " << my_hours << "\n\n" << my_type << "\n\n" << price_ticket << "\n\n";
		payment obj;
		obj.claculate_final_price(my_type, my_hours, price_ticket);
		int amount = obj.get_amount();
		return amount;
	}
	// User wants to book a seat in flight
	void book_a_seat(int user_id, int flight_id, string city) {
		int amount = manage_payment();
		short choice = 0;
		cout << "\n1) Business Class  ";
		cout << "\n2) Economy Class\nEnter:  ";
		cin >> choice;
		// so the Logic is we will go the Registration file of the Particular User
		// and will add his flight details 
		// to cancel we will do the same we will remove flight information from the user files
		switch (choice)
		{
		case 1:
		{
			int seat = 0;
			cout << "\nHow many Seats:\nEnter:";
			cin >> seat;
			while (true) {
				if (seat > (total_business_seats - business_seat_counter)) {
					cout << "\n Sorry! Avaliable Seats are: " << total_business_seats - business_seat_counter;
					cout << "\nEnter Number of Seats (enter 0 to return) :";
					cin >> seat;
				}
				else
				{
					break;
				}
			}
			
			// Let's add information to the user Text file
			add_flight_information_to_user(user_id,flight_id,"Business",seat,city);
			// Book a Business Class Seat
			for (size_t i = 0; i < seat; i++)
			{
				business_class_seats[business_seat_counter].set_is_taken(true);
				business_class_seats[business_seat_counter].set_seat_number(business_seat_counter);
				business_seat_counter++;
			}
			cout << "\n Total Price is: " << amount << "\n";
			cout << "\nYour Seats are Suceesfully Booked.\n";

			break;
		}
		case 2:
		{
			int seat = 0;
			cout << "\nHow many Seats:\nEnter:";
			cin >> seat;
			while (true) {
				if (seat > (total_economic_seats - economic_seat_counter)) {
					cout << "\n Sorry! Avaliable Seats are: " << total_economic_seats - economic_seat_counter;
					cout << "\nEnter Number of Seats (enter 0 to return) :";
					cin >> seat;
				}
				else
				{
					break;
				}
			}
			// Let's add information to the user Text file
			add_flight_information_to_user(user_id, flight_id, "Economic",seat,city);
			// Book a Business Class Seat
			for (size_t i = 0; i < seat; i++)
			{
				economic_class_seats[economic_seat_counter].set_is_taken(true);
				economic_class_seats[economic_seat_counter].set_seat_number(economic_seat_counter);
				economic_seat_counter++;
			}
			
			cout << "\n--There is Some Mistake with the Payment Information--\n Total Price is: " << amount << "\n";
			cout << "\nYour Seats are Suceesfully Booked.\n";
			break;
		}
		default:
			cout << "\nInvalid Choice.. Exiting\n";
			break;
		}
	}
	
	// Display the Taken Seats
	void display_avaliable_seats() {
		cout << "\nNumber of Business Seats Booked: " << business_seat_counter << "\n";
		cout << "Number ofEconomy Seats Booked: " << economic_seat_counter << "\n";
		cout << "Total Seats in Business Class: " << total_business_seats << "\n";
		cout << "Total Seats in Economic Class: " << total_economic_seats << "\n";
		cout << "Remaining Business Seats: " << total_business_seats - business_seat_counter;
		cout << "\nRemaining Economic Seats: " << total_economic_seats - economic_seat_counter << "\n";
	}
	~Flights() {
		delete[] economic_class_seats;
		delete[] business_class_seats;
	}
};




