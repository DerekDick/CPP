#include <iostream>
#include <iomanip>

class Date {
	/*Data member*/
	int month;
	int day;
	int year;

	/*Function member*/
public:
	//Access methods
	int getMonth() { return this->month; }
	int getDay() { return this->day; }
	int getYear() { return this->year; }
	void setMonth(int m) { this->month = ((m >= 1 && m <= 12) ? m : 1); return; }
	void setDay(int d) { this->day = d; return; }
	void setYear(int y) { this->year = y; return; }

	//Constructors
	Date() = default; //The default synthesized constructor
	Date(int m, int d, int y):
		month((m <= 12 && m >= 1) ? m : 1), day(d), year(y)
	{}

	void displayDate(std::ostream &os) {
		/*This function is used to print this date to the ostream os*/
		os << std::setfill('0') << std::setw(2) << this->month << '/'
			<< std::setfill('0') << std::setw(2) << this->day << '/'
			<< this->year << std::endl;
	}
};

int main() {
	//Testing some methods of the calss Date
	Date today(4, 12, 1992);
	today.displayDate(std::cout);
	today.setMonth(13);
	today.displayDate(std::cout);

	return 0;
}