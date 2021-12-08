Project Statement:
Develop an application namely New-PAK Airline Flight System (NPAFS) for a newly
established airline. PAFS is functional in five major cities of Pakistan. These cities are
Islamabad, Lahore, Quetta, Peshawar, and Karachi. Each city has two airports located at the
North and South. NPAFS team wants to have a flight reservation system. NPAFS has 20
airplanes in each city whereas maximum 5 can land at a time in an airport. NPAFS has
established a network of flights in 25 countries around the globe. Due to COVID situation some
countries have travel bans. NPAFS greatly value its passengers and abide by the international
travelling laws. 50,000 passengers use NPAFS annually. Ten Local flights and Five
International flights take off from each airport on daily basis depending on their schedule. Each
plane of NPAFS has seating capacity of 50 passengers in economy class and 10 in business
class during the COVID days. The days passengers are seated with a gap of one seat. The main
features identified by the NPAFS administration are as follows:

Menu: (10 marks)
A menu is provided to navigate the full system. After completion of each step users are
provided with a menu to the subsequent process and a link to main menu. Basic details about
NPAFS are available for every person without a login. System specific details like Flight
Reservation, and Cancellation etc. are only accessible to the registered users.

Login: (10 marks)
 Admin Panel: NPAFS has a team to manage the interaction with the system. The team
members can login to change the schedule of flights. Add new routes for local and
international flights. Restrict the number of passengers in a plane. Update airline
inquiry details.
 Passenger Panel: Users are the passengers that use to travel using NPAFS. A new user
can register in the system with a valid CNIC. An adult passenger can also register for
the dependents under 18.
Registration details are stored in two separate files namely Admin.txt and Passengers.txt.
These files have Usernames and Passwords. User can also reset the password and username.
The registration process hides the password and only shows ******** instead of actual
entered characters. New user must re-enter the password and system verify any typing
mistake. Password must be 8 characters long and use of minimum one special character,
uppercase, lowercase, and numeric digit is must. The passenger account is only created if
a valid 13-digit CNIC is provided and CNIC must not be repeated in existing record.
Otherwise, appropriate messages should be generated to notify the users. Users provide
their basic identification details to register.
A registered user is also asked to provide account details for payments and transactions.
Account details are verified through a non-member function “VerifyFinancialDetail” by a
Finance Department of NPAFS.

Flight Schedule: (10+10 marks)
Maintain a complete schedule of flights for each airplane, covering the following details:
 A plane can either travel locally or internationally in a single day.
 Number of hours required to complete a flight journey must be recorded.
 Arrival and Departure Time should be displayed for each flight.
 Current available seats regularly updated should be displayed in the information panel.
 A local flight is of short duration and a plane can have multiple journeys per day with
a gap of 2 hours.
 Indirect flights are also detailed with exact locations in the schedule. For example: A
flight from Pakistan to USA can be via UAE.
There must not be any clash between timings and maximum airplanes that can be at an airport
as described earlier. Both registered and un-registered users can search for schedule details
with customized keywords.
Find the shortest path between Pakistan and USA based on hours. A Special Flight (SF)
is dedicated to follow the shortest path once in a month. SF does not drop passengers to
countries coming in the shortest route. Provide the details about this SF, only to the users
who have maximum availed the NPAFS services. More specifically to those who
frequently travel between Pakistan and USA.

Passengers: (10 marks)
Passengers have a valid Passport. Passport can be Local or Foreign. Passport must have a stamp
of VISA for travelling. For a local journey VISA is not required but for international trips VISA
is a must. A passenger can register and login to the system. Details of the passenger can also
be updated. Passenger can view the detail of most visited country with an estimate of travelling
cost on NPAFS.
Maintain a travel history for passengers and offer 10% discount on booking a flight to those
passengers who travel frequently based on their previous month history.

Booking: (20 marks)
Passengers book a flight by providing and considering the following information:
 Selecting the country and destination airport details.
 Reserving a seat by considering the current available seats and schedule of flights.
 Route details for direct and indirect flights.
 Costs are provided for each available flight by overloaded stream operator.
Any user can search the available flights and timing details. Only a registered passenger can
reserve a seat. Passengers can update their details. Change their scheduled flight or even cancel
it with a penalty of 25% actual payment.
Due to COVID some flights may not be available but can be resumed. The system must allow
admin to resume or block flight schedule to a specific affected country.

Payment: (10 marks)
The payment details for each booked flight are recorded. Ticket price for all journeys is
displayed to the users.
 One hour travel costs Rs.10,000 for a local flight and Rs.20,000 for international flights.
 Government deducts 5% and 10% tax on local and international flights, respectively.
 A route from a country A to B can have C etc. in between, therefore the cost for a flight
depends on the route.

Requirements:
Phase-1
1. Design an UML class diagram and follow it throughout the implementation.
(5 marks)

2. Identify Aggregation (if any), Association (if any), Composition (if any), Virtual
Inheritance (if any), Polymorphism, member, non-member, virtual functions, static
and constant data members. (5 marks)
Phase-2
1. Follow all above mentioned details of the project and must use all OOP concepts. (80
marks)
2. Provide a common interface for displaying the results using Polymorphism in each
class hierarchy. (2 marks)
3. Use of dynamic array is compulsory wherever an array is required. (2 marks)
4. Provide parameterized constructors in each class. (1 mark)
5. Use destructor to destroy dynamically allocated memory. (1 mark)
6. Provide a copy constructor to deep copy where necessary. (1 mark)
7. Program must not stop execution for logical errors instead display an appropriate
message for 10 seconds and navigate to the main menu. (1 mark)
8. Use filing to store all data that needs to be stored for a longer duration. (1 mark)
9. Populate NPAFS application with sufficient data before submission, to
demonstrate each feature. (1 mark)
Use the below mentioned link or any other website to find details related to distances and
flight durations. You may also assume yourself and provide a graph or table for it.
https://distancecalculator.globefeed.com/Distance_Between_Countries.asp
