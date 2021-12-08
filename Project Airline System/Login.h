#pragma once
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
class Register;
class Login {
	int user_id;
	string email;
	string password;
	static bool is_logged_in;
	static bool is_admin_logged_in;
public:
	static int total_user;
	Login() {
		email = "ismail@gmail.com";
		password = "welcome12@1";
		logout_user();
		user_id = 0;
	}
	//
	int get_current_user_id() {
		return user_id;
	}
	void set_current_user_id(int i) {
		user_id = i;
	}

	string get_email() const {
		return email;
	}
	string get_password() const {
		return password;
	}
	//setter
	void set_email(string e) {

		if (e.find("@gmail.com") != string::npos) {
			email = e;
		}
		else
		{
			cout << "\n---Invalid Email..Must include @gmail.com---\n";
			cout << "Enter Again:";
			getline(cin, email);
			set_email(email);
		}
	}
	// Get login state
	static bool get_login_state() {
		return is_logged_in;
	}


	void enter_password() {
		string pass = "";
		char ch;
		cout << "Please enter Password\n";
		ch = _getch();
		// when the charater will be enter stop
		while (ch != 13) {
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		set_password(pass);
		/*
		if (pass == "ismai") {
			cout << "\nAccess granted :\n";
		}
		else {
			cout << "\nAccess aborted...\n";
		}*/
	}
	void set_password(string p) {
		int flag = 0;
		// Checking if string contians special character
		for (int i = 0; i < p.length(); i++)
		{
			if ((p[i] >= 48 && p[i] <= 57) ||
				(p[i] >= 65 && p[i] <= 90) ||
				(p[i] >= 97 && p[i] <= 122))
			{
				continue;
			}
			else
			{
				// so string contains special charater
				flag = 1;
				break;
			}
		}
		if(p.length() >= 8 && flag == 1)
			password = p;
		else {
			cout << "\n Password Minimum Length is 8 and must have a minimum one Special charater";
			enter_password();
		}
 	}
	//getting Login information
	void get_info() {
		string temp;
		cout << "Please enter your Email:";
		getline(cin, temp);
		set_email(temp);
		enter_password();
	}
	// function to log User out of His Account
	static void logout_user() {
		is_logged_in = false;
	}
	// function to log User In of His Account
	static void logIn_user() {
		is_logged_in = true;
	}
	static bool get_admin_login_state() {
		return is_admin_logged_in;
	}
	// function to log Admin out of His Account
	static void logout_admin() {
		is_admin_logged_in = false;
	}
	// function to log Admin In of His Account
	static void logIn_admin() {
		is_admin_logged_in = true;
	}
	void check_admin_credientials() {
		ifstream obj;
		bool flag_email = false;
		bool flag_password = false;
		
			obj.open("./Admin/admin.txt");
			if (!obj) {
				cout << "\n---Unable to open Admin Files---\n";
			}
			else
			{
				string line;
				while (getline(obj, line))
				{
					// mathcing the credientials with those which are in files
					if (email == line) {
						//cout << "email match";
						flag_email = true;
					}
					else
					{
						flag_email = false;
					}

				}
				obj.close();
			}

			obj.open("./Admin/password.txt");
			if (!obj) {
				cout << "\n---Unable to open Admin Files---\n";
			}
			else
			{
				string line;
				while (getline(obj, line))
				{
					// mathcing the credientials with those which are in files
					if (password == line) {
						//cout << "email match";
						flag_password = true;
					}
					else
					{
						flag_password = false;
					}
				}
				obj.close();
			}
				//making sure a  user cannot use the password of other and same for email
				if ((flag_email && flag_password)) {
					// let's make state of login As Logged in
					cout << "\Credientials Match.. You Now Update & Change Everything.";
					logIn_admin();
				}
				else
				{ // making email & password false for the next registered to check for
					cout << "\nInvalid Credientials\n";
					flag_email = false;
					flag_password = false;
				}
}	
	//function to check if credientials match
	void check_credientials() {
		ifstream obj;
		bool flag_email = false;
		bool flag_password = false;
		for (size_t i = 1; i <= total_user; i++)
		{
			string temp = to_string(i) + ".txt";
			obj.open("./Registered_Users/"+ temp);
			if (!obj) {
				cout << "\n---Unable to open Registered Files---\n";
				break;
			}
			else {
				string line;
				int line_no = 0;
				
				while (getline(obj, line))
				{
					// mathcing the credientials with those which are in files
					line_no++;
					if (line_no == 2)
					{
						if (email == line) {
							//cout << "email match";
							flag_email = true;
						}
					}
					if (line_no == 3) {
						if (password == line) {
							//cout << "password match";
							flag_password = true;
						}
					}
					
					if (flag_email && flag_password) {
					//	cout << "\ncorrect\n";
						// so we have found the credientials.. let's get user id
						//cout << "User ID: " << i << " ";
						set_current_user_id(i);
						break;
					}
				}
				obj.close();
				//making sure a  user cannot use the password of other and same for email
				if ((flag_email && flag_password)) {
					// let's make state of login As Logged in
					cout << "\Credientials Match.. You Can Now Book Your Flights";
					logIn_user();
					break;
				}
				else
				{ // making email & password false for the next registered to check for
					flag_email = false;
					flag_password = false;
				}
			}

		}
		// if email & password does not match
		if (!(flag_email && flag_password)) {
			cout << "\nInvalid Credientials\n";
			flag_email = false;
			flag_password = false;

		}
	}
};
	// Using Inheritance
class Register :public Login {
	string name;
	string cnic;
	string address;
	unsigned short age;
	unsigned long id;

public:
	
	Register(){
		name = "ismail";
		cnic = "1234567891234";
		address = "Islamabad";
		set_email("ismail@gmail.com");
		set_password("welcome12@1");
		age = 18;
		id = total_user;
	}
	//total number of users
	int get_total_user() {
		return total_user;
	}
	// Function to set CNIC
	void set_cnic(string c) {
		int l = c.length();
		if (l == 13)
			cnic = c;
		else
		{
			cout << "\n---Invalid Cnic---\n";
			cout << "Enter Again:";
			cin >> cnic;
			set_cnic(cnic);
		}
	}
	// Function to set Age
	void set_age(unsigned short n) {
		if (age >= 1 && age <= 250)
		{
			if (age >= 1 && age <= 250) {
				age = n;
			}
			else
			{
				cout << "\n---Invalid Age---\n";
				cout << "Enter Again:";
				cin >> age;
				set_age(age);
			}
		}
	}
	void set_name(string n){
		if(n.length() >= 2){
			name = n;
		 }
		else
		{
			cout << "\n---Invalid Name---\n";
			cout << "Enter Again:";
			getline(cin,name);
			set_name(name);
		}

	}
	// Getting all the information from user
		void get_info_from_user() {
			string temp;
			cout << "Please Enter your Age:";
			cin >> age;
			set_age(age);
			cout << "Please enter your name:";
			cin.ignore();
			getline(cin, name);
			set_name(name);
			cout << "Please enter your Address:";
			getline(cin, address);
			if (age >= 18)
			{
				cout << "\n------Equal to Or Above 18-----\n";
				cout << "Please enter your CNIC (No Dashes) :";
				cin >> cnic;
				set_cnic(cnic);
			}
			else
			{
				cout << "\n------You are a Dependent-----\n";
				cout << "Please enter Guardian CNIC (No Dashes) :";
				cin >> cnic;
				set_cnic(cnic);
			}
			cout << "Please enter Your Email: ";
			cin.ignore();
			getline(cin, temp);
			set_email(temp);

			enter_password();
		}
		//increase Number of users
		void static increase_total_user() {
			total_user++;
		}
		void write_registration_to_file() {
			increase_total_user();
			ofstream obj;
			string file_name = to_string(total_user) + ".txt";
			obj.open("./Registered_Users/"+ file_name);
			if (!obj) {
				cout << "\nUnable to Open Registration File\n";
			}
			else
			{
				obj << "User Id: " << total_user << "\n";
				obj << get_email();
				obj << "\n";
				obj << get_password();
				obj << "\n";
				obj << name << "\n" << cnic << "\n" << address << "\n" << age << "\n";
			}
			obj.close();
			cout << "\n---Congrats! Account Created Successfully. Now you can Login to this Application using Your Credientials---\n";
		}
	

};
int Login::total_user = 0;
bool Login::is_logged_in = false;
bool Login::is_admin_logged_in = false;

