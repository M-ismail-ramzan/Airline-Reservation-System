#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
class Flights_Schedule {
	// All the routes will be here.
	string from;
	string to;
	string distance;
	float est_time;
	string status;
	string departure_time;
	string indirect_path;
	string route_taken;
	string type;
	string arrival_time;
	int id_flight;
	int ticket_price;
public:
	Flights_Schedule() {
		from = "";
		to = "";
		distance = "";
		est_time = 0;
		status = "";
		departure_time = "";
		indirect_path = "";
		route_taken = "";
		type = "";
		arrival_time = "";
		id_flight = -1;
		ticket_price = 0;
	}
	// parametrize constructor
	Flights_Schedule(string f, string t, string d, float e, string s, string dt, string i, string ty, string at, int id) {
		from = f;
		to = t;
		distance = d;
		est_time = e;
		status = s;
		indirect_path = i;
		departure_time = dt;
		type = ty;
		arrival_time = at;
		id_flight = id;
	}
	
	// get type
	string get_type_flight() {
		return type;
	}
	float get_estimation_time() {
		return est_time;
	}
	// get the information from user
	void set_Flights_info() {
		cin.ignore();
		cout << "\nYou already have Selected City. Please Let us Know About Airport (South or North) and The place where you want Go\nExample Input: \nEnter From: South \nEnter To: Finland\n\n";
		cout << "Enter From (Country or City) OR (Airport North or South): ";
		getline(cin, from);
		cout << "Enter To (Country or City) OR (Airport North or South): ";
		getline(cin, to);
	}
	// Getting the Detail of One Single Flight
	void get_particular_flight_detail(string city, int flight_id) {
		ifstream obj;
		obj.open("./Schedule/" + city + ".csv");
		if (!obj) {
			cout << "Unable to Open File";
		}
		else {
			string line;
			while (getline(obj, line)) {
				string temp[10];
				stringstream string_stream(line);  // creating string stream object
				int i = 0;            // declaring i and assign  to 0
				while (string_stream.good())   // loop will continue if string stream is error free
				{
					string a;
					getline(string_stream, a, ',');   //calling getline fuction
					temp[i] = a;	// store each detail in variable array
					i++;
				}
				// let's get the required flight Details
				if ((temp[8]) == to_string(flight_id)) {
					cout << "\n[+] --- Flight Information --- [+]\n";
					ticket_price = stoi(temp[9]);
					id_flight = stoi(temp[8]);
					cout << "\n Flight ID: " << id_flight << "\n";
					cout << "\nCity: " << city;
					from = temp[0];
					cout << "\nFrom:" << from;
					to = temp[1];
					cout << "\nTo:" << to;
					departure_time = temp[2];
					cout << "\nDeparture Time:" << departure_time;
					distance = temp[3];
					cout << "\nDistance:" << distance << " km";
					// Calculating estimation time
					est_time = stoi(distance) / (567 * 1.609);
					cout << "\nEstimation Flight Time with Speed 567 mph will be " << est_time << "\n";
					// Calculating the Arriaval time
					arrival_time_calculator();
					cout << "Arrival Time: " << arrival_time << "\n";
					type = temp[7];
					cout << "Flight Type: " << type << "";
					status = temp[4];
					cout << "\nStatus:" << status;

					cout << "\n---Other Information--";
					indirect_path = temp[5];
					if (indirect_path != "No")
						cout << "\nThis Flight can have Indirect Path Through " << indirect_path;
					else
						cout << "\nNo Indirect Path Found for this Particular Flight";
					route_taken = temp[6];
					cout << "\nThis FLight Will Pass through " << route_taken << "  Country\n";
					cout << "\nTicket Price: " << ticket_price << "\n";
				}
			}
			obj.close();
		}
	}
	// Writing to the schedule file
	void change_the_schedule_of_flight(string city, int flight_id) {
		ifstream obj;
		obj.open("./Schedule/" + city + ".csv");
		if (!obj) {
			cout << "Unable to Open File";
		}
		else {
			cout << "\n--I was able to Open the Particular File & Get the Index of Particular Flight. But I did not write function that would change the content of that Particular ID--\n";
		}
		obj.close();
	}
	//opeing text file to get all the details
	void get_details_from_file(string city) {
		bool found = false;

		ifstream obj;
		obj.open("./Schedule/" + city + ".csv");
		if (!obj) {
			cout << "Unable to Open File";
		}
		else
		{

			string line;
			while (getline(obj, line)) {
				//making sure we got for which user searched
				short test1 = -1;
				short test2 = -1;
				test1 = line.find(to);
				test2 = line.find(from);

				if (test1 != -1 || test2 != -1) {

					//cout << "\nRequested Flight: " << line << "\n";

					string temp[10];
					stringstream string_stream(line);  // creating string stream object
					int i = 0;            // declaring i and assign  to 0
					while (string_stream.good())   // loop will continue if string stream is error free
					{
						string a;
						getline(string_stream, a, ',');   //calling getline fuction
						temp[i] = a;	// store each detail in variable array
						i++;
					}
					// Adding string array to the class varaibles
					if ((from == temp[0] && to == temp[1]) || (from == temp[1] && to == temp[0])) {
						cout << "\n[+] --- Flights Found --- [+]\n";
						ticket_price = stoi(temp[9]);
						id_flight = stoi(temp[8]);
						cout << "\n Flight ID: " << id_flight << "\n";
						cout << "\nCity: " << city;
						from = temp[0];
						cout << "\nFrom:" << from;
						to = temp[1];
						cout << "\nTo:" << to;
						departure_time = temp[2];
						cout << "\nDeparture Time:" << departure_time;
						distance = temp[3];
						cout << "\nDistance:" << distance << " km";
						// Calculating estimation time
						est_time = stoi(distance) / (567 * 1.609);
						cout << "\nEstimation Flight Time with Speed 567 mph will be " << est_time << "\n";
						// Calculating the Arriaval time
						arrival_time_calculator();
						cout << "Arrival Time: " << arrival_time << "\n";
						type = temp[7];
						cout << "Flight Type: " << type << "";
						status = temp[4];
						cout << "\nStatus:" << status;

						cout << "\n---Other Information--";
						indirect_path = temp[5];
						if (indirect_path != "No")
							cout << "\nThis Flight can have Indirect Path Through " << indirect_path;
						else
							cout << "\nNo Indirect Path Found for this Particular Flight";
						route_taken = temp[6];
						cout << "\nThis FLight Will Pass through " << route_taken << "  Country\n";
						cout << "\nTicket Price: " << ticket_price << "\n";

						found = true;
					}
				}
			}
		}
		obj.close();
		if (found == false) {
			cout << "\nSorry! No Such Flights Found. Try Searching South to Finland..\n";
		}


	}
	void arrival_time_calculator() {
		int hours = (unsigned int)est_time;
		int mins = 60 * ((est_time - (unsigned int)est_time));
		// Split the First part
		string  first_token = departure_time.substr(0, departure_time.find(":"));
		// Split the second part
		string  second_token = departure_time.substr(departure_time.find(":") + 1, departure_time.find("\n"));
		// let's find the minutes for arrival time
		mins = stoi(second_token) + mins;
		if (mins >= 60) {
			mins = 60 - mins;
			hours++;
		}
		// Hours for the Arrival time
		hours = stoi(first_token) + hours;
		if (hours >= 24) {
			hours = hours - 24;
		}
		arrival_time = to_string(hours) + ":" + to_string(mins);

	}
	// getter ticket
	int get_ticket_price() {
		return ticket_price;
	}
};
