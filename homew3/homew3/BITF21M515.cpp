#include "iostream"

using namespace std;

class RationalNo
{
	//data members

	int numerator;

	int denominator;

public:

	// constructors

	RationalNo(int numerator1, int denominator1)
	{

		setN(numerator1);

		setD(denominator1);
	
	}

	RationalNo(int numerator1)
	{

		setN(numerator1);
	
	}

	// setters

	void setN(int numerator)
	{

		this->numerator = numerator;
	
	}

	void setD(int denominator)
	{

		if (denominator > 0)
		{
			this->denominator = denominator;
		}

		else
		{
			this->denominator = 1;
		}
	
	}

	// getters

	int getN()
	{

		return this->numerator;
	
	}

	int getD()
	{

		return this->denominator;
	
	}

	//Plus(+) binary operator

	RationalNo operator+ (const RationalNo& obj) const
	{

		RationalNo temp(0,0);

		temp.numerator = numerator * obj.denominator + denominator * obj.numerator;
		
		temp.denominator = denominator * obj.denominator;

		return temp;
	
	}

	//Minus (-) binary operator

	RationalNo operator- (const RationalNo& obj) const
	{

		RationalNo temp(0, 0);

		temp.numerator = numerator * obj.denominator - denominator * obj.numerator;

		temp.denominator = denominator * obj.denominator;

		return temp;
	
	}

	//multiply (*) binary operator

	RationalNo operator* (const RationalNo& obj) const
	{

		RationalNo temp(0, 0);

		temp.numerator = numerator * obj.numerator;

		temp.denominator = denominator * obj.denominator;

		return temp;
	
	}

	//divide(/) binary operator

	RationalNo operator/ (const RationalNo& obj) const
	{

		RationalNo temp(0, 0);

		temp.numerator = numerator * obj.denominator;

		temp.denominator = denominator * obj.numerator;

		return temp;
	
	}

	//equal(==) binary operator

	bool operator== (const RationalNo& obj) const
	{

		return ((numerator * obj.denominator) == ( denominator * obj.numerator));
	
	}

	//Minus (–) unary operator

	RationalNo operator- () const
	{
		if (numerator > 0)
		{
			return RationalNo((-numerator), (denominator));
		}

		else
		{
			return RationalNo((numerator), (denominator));
		}
		
	}

	//logic not (!) unary operator
	
	bool operator! () const
	{

		return (numerator < 0 || denominator < 0);
	
	}

	//Less-than (<) binary operator

	bool operator< (const RationalNo& obj) const
	{

		return ((numerator * obj.denominator) < (denominator * obj.numerator));
	
	}

	friend ostream& operator<< (ostream&, const RationalNo&);

	friend istream& operator>> (istream&, RationalNo&);
};

ostream& operator<< (ostream& print, const RationalNo& obj)
{

	print << obj.numerator << "/" << obj.denominator << endl;

	return print;

}

istream& operator>> (istream& input, RationalNo& obj)
{

	cout << "ENter numertor: ";
	input >> obj.numerator;

	cout << "Enter denominator: ";
	input >> obj.denominator;

	return input;

}
int main()
{
	RationalNo o1(6, 7), o2(4, 5);

	cout << o1;

	cout << o2;

	cout << o1 / o2;

	cout << o1 + o2;

	cout << o1 - o2;
	
	cout << o1 * o2;

	return 0;
}