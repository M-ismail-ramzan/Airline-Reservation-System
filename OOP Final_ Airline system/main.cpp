#include <iostream>
#include <string>
#include "./Login.h"
#include "./Airport.h"

using namespace std;
void show_flights(string city);
void show_select_menu() {
	short select = 0;
	cout << "\n Please Select the City From which You want to Go or Land to that City from Other Flights \n";
	cout << "1) Islamabad\n";
	cout << "2) Karachi\n";
	cout << "3) Lahore\n";
	cout << "4) Quetta\n";
	cout << "5) Peshwar\n";
	cout << "Enter: ";
	cin >> select;
	string temp = "";
	switch (select)
	{
	case 1:
	{
		// sending the city to search for Flights
		temp = "islamabad";
		show_flights(temp);
		break;
	}
	case 2:
	{
		// sending the city to search for Flights
		temp = "karachi";
		show_flights(temp);
		break;
	}
	case 3:
	{
		// sending the city to search for Flights
		temp = "lahore";
		show_flights(temp);
		break;
	}
	case 4:
	{
		// sending the city to search for Flights
		temp = "quetta";
		show_flights(temp);
		break;
	}
	case 5:
	{
		// sending the city to search for Flights
		temp = "peshawar";
		show_flights(temp);
		break;
	}
	default:
		cout << "\n Invalid Option Selected \n Exiting...\n";
		break;
	}

}
string select_city_for_book(){
	short select = 0;
	cout << "\n Please Select the City From which You want to Go or Land to that City from Other Flights \n";
	cout << "1) Islamabad\n";
	cout << "2) Karachi\n";
	cout << "3) Lahore\n";
	cout << "4) Quetta\n";
	cout << "5) Peshwar\n";
	cout << "Enter: ";
	cin >> select;
	string temp = "";
	switch (select)
	{
	case 1:
	{
	// just a function to return the city on the basis of selection
		temp = "islamabad";
		return temp;
		break;
	}
	case 2:
	{
		temp = "karachi";
		return temp;
		break;
	}
	case 3:
	{
		temp = "lahore";
		return temp;
		break;
	}
	case 4:
	{
		temp = "quetta";
		return temp;
		break;
	}
	case 5:
	{
		temp = "peshawar";
		return temp;
		break;
	}
	default:
		cout << "\n Invalid Option Selected \n Exiting...\n";
		break;
	}

}
void show_booking_flight_menu(Flights* flight, int user_id) {
	int select = 0;
	cout << "\n Do you want to Book Flight From Above Results ?";
	cout << "\n1) Yes ";
	cout << "\n2) No\n Enter: ";
	cin >> select;
	switch (select)
	{
	case 1: {
		// call the Function to Book Flight
		int flight_id;
		//cout << "\n Calling the Function to Book the Flight \n";
		//cout << "\n Remember Flight will be Booked with city and the ID \n";
		cout << "\nPlease Enter Flight ID: " ;
		cin >> flight_id;
		// validating the input
		while (true)
		{
			if (flight_id >= 0 && flight_id <= 19) {
				break;
			}
			else
			{
				cout << "\nInvalid Flight ID\n Enter Again:";
				cin >> flight_id;
			}
		}
		string city = select_city_for_book();
		// if everything goes right now let's book the flight for the User
		// Flight ID ->
		// User ID ->
		// Number of Searts..
		// finding the appropirate id of the fight because we have cities as well..
		int index = 0;
		int j = 0;
		for (size_t i = 0; i < 100; i++,j++)
		{
			if (j >= 19) {
				j = 0;
			}
			// looking for the specific flight
			if ((flight[i].get_city_flight() == city) && (j == flight_id)) {
				index = i;
			}
		}
		cout << "\n--Your Ticket is for This Flight-- \n";
		int unique = flight[index].get_flight_id();
		flight[index].return_full_schedule(city, unique);
		flight[index].book_a_seat(user_id,index,city);
		flight[index].display_avaliable_seats();
		
		break;
	}
	case 2:
	{
		cout << "\n[+]--- Taking you back to Registered Menu --- [+]";
		break;
	}
	default:
		cout << "\n[+]--- Invalid Input.. Exiting --- [+]";
		break;
	}
}

void read_user_files(int user_id, int &flight_no, string &seat_class, int &no_of_Seats,string &city)
{
	//user_id = 1;
	ifstream obj;
	string temp = to_string(user_id) + ".txt";
		obj.open("./Registered_Users/" + temp);
		if (!obj) {
			cout << "\n---Unable to open Registered Files---\n";
		}
		else {
			string line;
			int line_no = 0;

			while (getline(obj, line))
			{
				// mathcing the credientials with those which are in files
				line_no++;
				if (line_no == 8)
				{
					if (line != "") {
						flight_no = stoi(line);
					}
				}
				if (line_no == 9) {
					if (line != "") {
						seat_class = (line);
					}
				}
				if (line_no == 10) {
					if (line != "") {
						no_of_Seats = stoi(line);
					}
				}
				if (line_no == 11) {
					if (line != "") {
						city = (line);
					}
				}
			}
			obj.close();
	}
}

void see_all_flight_with_details(Flights* flight) {
	const int each_city_max_flight = 20;
	int index = 0;
	string n;
	cout << "\n Enter Anything to see all the Flight From Islamabad City \nEnter:";
	cin >> n;
	// Showing all the details from islamabad
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		int unique = flight[index].get_flight_id();
		flight[index].return_full_schedule("islamabad", unique);
		index++;
	}
	cout << "\n Enter Anything to see all the Flight From Karachi City \nEnter:";
	cin >> n;
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		int unique = flight[index].get_flight_id();
		flight[index].return_full_schedule("karachi", unique);
		index++;
	}
	cout << "\n Enter Anything to see all the Flight From Lahore City \nEnter:";
	cin >> n;
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		int unique = flight[index].get_flight_id();
		flight[index].return_full_schedule("lahore", unique);
		index++;
	}
	cout << "\n Enter Anything to see all the Flight From Peshwar City \nEnter:";
	cin >> n;
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		int unique = flight[index].get_flight_id();
		flight[index].return_full_schedule("peshwar", unique);
		index++;
	}
	cout << "\n Enter Anything to see all the Flight From Quetta City \nEnter:";
	cin >> n;
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		int unique = flight[index].get_flight_id();
		flight[index].return_full_schedule("quetta", unique);
		index++;
	}
}
void show_logged_in_menu(Flights* flight,int user_id) {
	while(true){
	short choice;
	choice = 0;
	cout << "\n[1] -> Search for Different Flights to Book";
	cout << "\n[2]-> See All the Flights\n";
	cout << "[3] -> Cancel Booked Seats \n";
	cout << "[4] -> Logout From Account\n";
	cout << "\nPlease Select the Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		// Calling the Function to make sure that the 
		show_select_menu();
		show_booking_flight_menu(flight,user_id);
		break;
	}
	case 2: {
		see_all_flight_with_details(flight);
		break;
	}
	case 3: {
		// We need The user_id to see his Flight Details..
		// If There will be no Seats simply say No Seats
		// else we will change the details of avaliable seats of that particular flight
		int flight_no = 0;
		string city = "";
		int no_of_Seats = 0;
		string seat_class = "";
		read_user_files(user_id,flight_no,seat_class,no_of_Seats,city);
		if(city == "")
			cout << "\nSorry! You do not Have Reserved Any Seat\n";
		else
		{
			cout << "\n--Your Ticket is for This Flight-- \n";
			int unique = flight[flight_no].get_flight_id();
			flight[flight_no].return_full_schedule(city, unique);
			flight[flight_no].cancel_seats(user_id,seat_class,no_of_Seats,city);
		}
		break;
	}
	default:
		break;

	}
	if (choice == 4) {
		break;
	}
	}
}
void show_admin_menu(Flights* flight) {
	while (true) {
	short choice;
	choice = 0;
	cout << "\n[1] -> Change Flight Details by it's ID & City\n";
	cout << "[2]-> See All the Flights\n";
	cout << "[3] -> Logout From Account\n";
	cout << "\nPlease Select the Choice:";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		string city= select_city_for_book();
		int flight_id = 0;
		cout << "\nPlease Enter the ID of the Flight \n";
		cin >> flight_id;
		// finding the appropirate id of the fight because we have cities as well..
		int index = 0;
		int j = 0;
		for (size_t i = 0; i < 100; i++, j++)
		{
			if (j >= 19) {
				j = 0;
			}
			// looking for the specific flight
			if ((flight[i].get_city_flight() == city) && (j == flight_id)) {
				index = i;
			}
		}

		flight[index].change_schedule_by_admin(city, flight_id);
		break;
	}
	case 2: {
		see_all_flight_with_details(flight);
		break;
	}
	case 3: {
		Login::logout_admin();
	}
	default:
		cout << "\n-- Invalud Choice-- \n";
		break;
	}
	if (choice == 3)
		break;
	}
}
void show_menu(Flights* flight) {
	while (true) {
		// Menu for the Normal User without Registration
		short choice;
		choice = 0;
		cout << "\n[1] -> Search for Different Flights \n";
		cout << "[2] -> Create Your Account \n";
		cout << "[3] -> Login To Your Account \n";
		cout << "[4] -> Login as Admin\n";
		cout << "[5] -> Exit\n";
		cout << "\nPlease Select the Choice:";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			// Calling the Function to make sure that the 
			show_select_menu();
			// here i will check if user is Login or Not
			cout << "\nYou Need to Register Yourself to Book Your Flight \n";

			break;
		}
		case 2:
		{
			// Register the Users
			Register obj1;
			obj1.get_info_from_user();
			obj1.write_registration_to_file();
			break;
		}
		case 3:
		{
			// Login User
			Login obj;
			obj.get_info();
			obj.check_credientials();
			if (Login::get_login_state()) {
				// show him Login Menu
				int user_id = obj.get_current_user_id();
				show_logged_in_menu(flight,user_id);
			}
			break;
		}
		case 4:
		{
			// Login User
			Login obj;
			obj.get_info();
			obj.check_admin_credientials();
			if (Login::get_admin_login_state()) {
				// show him Admin Menu
				show_admin_menu(flight);
			}
			break;
		}
		case 5: {
			cout << "\nThanks for Using Our Application\n";
			break;
		}
		default:
			cout << "\nInvalid Selection...";
			break;
		}
		if (choice == 5)
			break;
	}
}
int main()
{	
	cout << "\n New-PAK Airline Flight System (NPAFS) \n\n Our Airports are at:";
	// Total 5 Cities has the Airline.
	City city[5]{City("Islambad"),City("Lahore"),City("Karachi"),City("Quetta"),City("Peshawar")};
	// Each of these Cities has 2 Airports.
	for (size_t i = 0; i < 5; i++)
	{
		city[i].display_city();
		//city[i].set_airports_name();
		//city[i].display_airports_name();
	}
	
	// Suppose we have just 3 flights
	Flights* flight = new Flights[100];
	const int each_city_max_flight = 20;
	int index = 0;
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		flight[index].set_id(i);
		flight[index].set_city("islamabad");
		index++;
	}
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		flight[index].set_id(i);
		flight[index].set_city("karachi");
		index++;
	}
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		flight[index].set_id(i);
		flight[index].set_city("lahore");
		index++;
	}
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		flight[index].set_id(i);
		flight[index].set_city("peshwar");
		index++;
	}
	for (size_t i = 0; i < each_city_max_flight; i++)
	{
		flight[index].set_id(i);
		flight[index].set_city("quetta");
		index++;
	}
	// Booking a seat
	//flight[2].book_a_seat();
	//flight[2].display_avaliable_seats();
	//flight[0]
	
		show_menu(flight);
	
	//flight[4].return_full_schedule(pass city);
	

	// Suppose a new User came to our website for registration
	//Register obj1;
	//obj1.get_info_from_user();
	//obj1.write_registration_to_file();
	// 
	//testing the login functionality
	//Login nu;
	//nu.get_info();
	//nu.check_credientials();

	/*****Testing Routes*/
	
	//route_taken();
}
