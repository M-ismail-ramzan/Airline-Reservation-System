#pragma once
class Seat {
	int seat_number;
	bool is_taken;
public:
	Seat() {
		seat_number = 0;
		is_taken = false;
	}
	Seat(int sn, bool busniess, bool taken) {
		seat_number = sn;
		is_taken = taken;
	}
	// setter functions
	void set_seat_number(int n) {
		seat_number = n;
	}
	void set_is_taken(bool taken) {
		is_taken = taken;
	}
};

