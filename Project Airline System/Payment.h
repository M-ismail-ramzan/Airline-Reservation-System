#pragma once
#include <string>
using namespace std;
class payment {
	long amount;
	float tax;
public:
	payment() {
		amount = 0;
		tax = 0;
	}
	// getter
	long get_amount() {
		return amount;
	}
	int get_tax() {
		return tax;
	}
	// setter functions
	void set_tax(int ta) {
		tax = ta;
	}
	void set_amount(long amo) {
		amount = amo;
	}
	// calculate the Total Amount
	void claculate_final_price(string type, int hours, long ticket_price) {
		if (type == "local") {
			cout << "\n\n---Hours---\n\n";
	
			for (size_t i = 0; i < hours; i++)
			{
				amount = amount + 10000;
			}
			amount = ticket_price + amount;
			// removeing tax

			amount = amount * 0.95;
			
		}
		else if (type == "international") {
			for (size_t i = 0; i < hours; i++)
			{
				amount = amount + 20000;
			}
			amount = ticket_price + amount;
			// removeing tax

			amount = amount * 0.90;
			
		}

	}
};