#include "iostream"
#include "string"

using namespace std;

class Date
{
	// data members

	int day;

	int month;
	
	int year;

public:

	//setters
	void setD(int day)
	{
		if (day >= 1 && day <= 31)
		{
			this->day = day;
		}

		else
		{
			this->day = 1;
		}
	}

	void setM(int month)
	{
		if (month >= 1 && month <= 12)
		{
			this->month = month;
		}

		else
		{
			this->month = 1;
		}
	}

	void setY(int year)
	{
		if (year >= 1900)
		{
			this->year = year;
		}

		else
		{
			this->year = 1900;
		}
	}

	//getters

	int getD()
	{
		return day;
	}

	int getM()
	{
		return month;
	}

	int getY()
	{
		return year;
	}

	// parameterized constructor

	Date(int day, int month, int year)
	{
		setD(day);
		setM(month);
		setY(year);
	}

	Date(int month, int year)
	{
		this->day = 1;
		setM(month);
		setY(year);
	}

	// default constructor

	Date()
	{
		this->day = 1;
		this->month = 1;
		this->year = 1900;
	}

	//pre - increment(++)
	Date operator++()
	{
		if (day == 31 && month == 12)
		{
			++day;
			++month;
			++year;

			setD(day);
			setM(month);
		}
		
		else if (day == 31)
		{
			++day;
			++month;

			setD(day);
			
		}

		else
		{
			++day;
			setD(day);
		}

		return *this;
	}

	//post-increment (++)
	Date operator++ (int)
	{
		Date oldSate(*this);

		if (day == 31 && month == 12)
		{
			day++;
			month++;
			year++;

			setD(day);
			setM(month);
		}

		else if (day == 31)
		{
			day++;
			month++;

			setD(day);
			
		}

		else
		{
			day++;
			setD(day);
		}

		return oldSate;
	}

	//pre-decrement (--)

	Date operator-- ()
	{
		if (day == 1 && month == 1)
		{
			--day;
			--month;
			--year;
		}
		else if (day == 1)
		{
			day = 31;
			--month;
		}

		else
		{
			--day;
		}
		return *this;
	}

	//post - decrement(--)

	Date operator-- (int)
	{
		Date oldState(*this);

		if (day == 1 && month == 1)
		{
			day--;
			month--;
			year--;
		}
		else if (day == 1)
		{
			day = 31;
			month--;
		}

		else
		{
			day--;
		}
		
		return oldState;;
	}

	//subtraction(-) binary

	int operator- (Date& obj)
	{
		Date temp;

		temp.day = this->day - obj.day;

		temp.month = this->month - obj.month;

		temp.year = this->year - obj.year;

		return temp.day;
		
	}

	//addition (+) unary

	bool operator+ ()
	{
		return ((day == 5 && month == 2) || (day == 23 && month == 3) || 
			(day == 1 && month == 5));
	}

	friend ostream& operator<< (ostream&, const Date&);
	friend istream& operator>> (istream&, Date&);
};

ostream& operator<< (ostream& print, const Date& obj)
{
	string monthName;
	
	if (obj.month == 1)
	{
		monthName = "January";
	}

	else if (obj.month == 2)
	{
		monthName = "Febrary";
	}

	else if (obj.month == 3)
	{
		monthName = "March";
	}

	else if (obj.month == 4)
	{
		monthName = "April";
	}

	else if (obj.month == 5)
	{
		monthName = "May";
	}

	else if (obj.month == 6)
	{
		monthName = "June";
	}

	else if (obj.month == 7)
	{
		monthName = "July";
	}

	else if (obj.month == 8)
	{
		monthName = "August";
	}

	else if (obj.month == 9)
	{
		monthName = "September";
	}

	else if (obj.month == 10)
	{
		monthName = "October";
	}

	else if (obj.month == 11)
	{
		monthName = "November";
	}

	else
	{
		monthName = "December";
	}

	print << monthName << " " << obj.day
		  << ", " << obj.year << endl;

	return print;
}

istream& operator>> (istream& input, Date& obj)
{
	cout << "Enter day: ";
	input >> obj.day;

	cout << "Enter month: ";
	input >> obj.month;
	
	cout << "Enter year: ";
	input >> obj.year;

	obj.setD(obj.day);
	obj.setM(obj.month);
	obj.setY(obj.year);

	return input;
}
int main()
{
	Date o1(18, 5, 2020), o2(10,5,2019), o3(1,12,2018);

	cout << o1;
	++o1;
	cout << o1;

	cout << endl;

	cout << o2;
	o2++;
	cout << o2;

	cout << endl;

	cout << o3;
	o3--;
	cout << o3;

	cout << endl;

	cout << o1.operator+();

	cout << endl;

	cout << o1.operator-(o2);

	return 0;
}