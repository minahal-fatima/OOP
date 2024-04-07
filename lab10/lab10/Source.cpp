#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches& right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches& right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches& right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches& right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches& right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches& right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches& right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream& out, const FeetInches& obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream& in, FeetInches& obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

class RoomDimension
{

	FeetInches lenght;

	FeetInches width;

public:

	void setL(int feet,int inches)
	{
		lenght.setFeet(feet);
		lenght.setInches(inches);
	}

	void setW(int feet, int inches)
	{
		width.setFeet(feet);
		width.setInches(inches);
	}

	FeetInches getL()
	{
		lenght.getFeet();
		lenght.getInches();

		return lenght;
	}

	FeetInches getW()
	{
		width.getFeet();
		width.getInches();

		return width;
	}

	RoomDimension(FeetInches lenght,FeetInches width) : lenght(lenght), width(width)
	{


	}

	FeetInches getArea()
	{
		return lenght * width;
	}

	void print()
	{
		cout << lenght << " " << width << endl;
	}


};
class  RoomCarpet
{
	RoomDimension roomSize;

	float costPerSquareFoot;

public:

	void setR(int lenghtFeet,int lenghtinches,int widthfeet,int widthInches)
	{
		roomSize.setL(lenghtFeet,lenghtinches);
		roomSize.setW(widthfeet, widthInches);
	}

	void setC(float  costPerSquareFoot)
	{
		this->costPerSquareFoot = costPerSquareFoot;
	}

	RoomDimension getL()
	{
		roomSize.getL();
		roomSize.getW();
	}

	RoomCarpet(RoomDimension roomSize, float costPerSquareFoot):roomSize(roomSize)
	{
		this->costPerSquareFoot = costPerSquareFoot;
	}

	static float totalCost(RoomDimension c,float cost)
	{
		return cost * (c.getL().getFeet() * c.getW().getFeet());
	}

	void print()
	{
		roomSize.print();
		cout << costPerSquareFoot << endl;
	}

};

int main()
{
	FeetInches o1(2, 3);

	FeetInches o2(4, 5);

	RoomDimension ob(o1,o2);

	ob.print();

	cout << ob.getArea();

	RoomCarpet ob2(ob, 4);

	ob2.print();

	cout << RoomCarpet::totalCost(ob, 4);

	FeetInches l1, w1;
	float cos;

	cout << "Enter 1st lenght: ";
	cin >> l1;

	cout << "Enter 2nd lenght: ";
	cin >> w1;

	cout << "Enter cost: ";
	cin >> cos;

	RoomDimension obj(l1, w1);

	RoomCarpet obj1(obj, cos);
	 
	
	cout << RoomCarpet::totalCost(obj, cos);
	return 0;
}