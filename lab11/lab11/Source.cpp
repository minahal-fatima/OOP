#include "iostream"

#include "string"

using namespace std;

class Employee
{
	string firstName;
	string lastName;
	string SSN;

public:

	Employee(string firstName, string lastName, string SSN)
	{
		this->firstName = firstName;

		this->lastName = lastName;

		this->SSN = SSN;
	}

	void setF(string firstName)
	{
		this->firstName = firstName;
	}

	string getF() const
	{
		return firstName;
	}

	void setL(string lasstName)
	{
		this->lastName = lastName;
	}

	string getL() const
	{
		return lastName;
	}

	void setS(string SSN)
	{
		this->SSN = SSN;
	}

	string getS() const
	{
		return SSN;
	}

	virtual void print()
	{
		cout << "NAME: " << firstName << " " << lastName << endl;
		
		cout << "SSN: " << SSN << endl;
	}

	virtual double earnings() = 0;


};
class SalariedEmployee : public Employee
{
	double weeklySalary;

public:

	SalariedEmployee(string firstName, string lastName, 
		string SSN, double weeklySalary): Employee(firstName,lastName,SSN)
	{
		this->weeklySalary = weeklySalary = 0;
	}

	void setW(double weeklySalary)
	{
		this->weeklySalary = weeklySalary;
	}

	double getW()const
	{
		return weeklySalary;
	}

	void print()
	{
		Employee::print();

		cout << "WEEKLY SALARY: " << weeklySalary << endl;
	}

	double earnings()
	{
		return weeklySalary;
	}

};
class HourlyEmployee:public Employee
{
	double wage;

	double hours;

public:

	HourlyEmployee(string firstName, string lastName,
		string SSN, double wage, double hours) : Employee(firstName,lastName,SSN)
	{
		this->wage = wage = 0;

		this->hours = hours = 0;
	}

	void setA(double wage)
	{
		this->wage = wage;
	}

	double getA()const
	{
		return wage;
	}

	void setH(double hours)
	{
		this->hours = hours;
	}

	double getH()const
	{
		return hours;
	}

	void print()
	{
		Employee::print();

		cout << "WAGE: " << wage << endl << "HOURS: " << hours << endl;
	}

	double earnings()
	{
		return wage * hours;
	}

};
class CommissionEmployee : public Employee
{
	double grossSales;

	double commissionRate;

public:

	CommissionEmployee(string firstName, string lastName, string SSN,
		double grossSales, double commissionRate) : Employee(firstName, lastName, SSN)
	{
		this->grossSales = grossSales = 0;

		this->commissionRate = commissionRate = 0;
	}

	void setG(double grossSales)
	{
		this->grossSales = grossSales;
	}

	double getG()const
	{
		return grossSales;
	}

	void setC(double commissionRate)
	{
		this->commissionRate = commissionRate;
	}

	double getC()const
	{
		return commissionRate;
	}

	void print()
	{
		Employee::print();

		cout << "GROSS SALES: " << grossSales << endl;

		cout << "COMMISION RATE: " << commissionRate << endl;
	}

	double earnings()
	{
		return grossSales * commissionRate;
	}
};
class BasePlusCommisssionEmployee : public CommissionEmployee
{
	double baseSalary;

public:

	BasePlusCommisssionEmployee(string firstName, string lastName, string SSN,double grossSales,
		double commissionRate, double baseSalary):CommissionEmployee(firstName,lastName,SSN,grossSales,commissionRate)
	{
		this->baseSalary = baseSalary = 0;
	}

	void setB(double baseSalary)
	{
		this->baseSalary = baseSalary;
	}

	double getB()const 
	{
		return baseSalary;
	}

	void print()
	{
		Employee::print();
		CommissionEmployee::print();

		cout << "BASE SALARY: " << baseSalary << endl;
	}

	double earnings()
	{
		return CommissionEmployee::earnings() + baseSalary;
	}
};
int main()
{
	SalariedEmployee ob1("Minahal", "Fatima", "BITF21M515",30000);
	ob1.setW(30000);
	
	ob1.print();
	
	cout << endl;
	
	cout << ob1.earnings();

	cout << endl;

	HourlyEmployee ob2("Minahal", "Fatima", "BITF21M515", 30.00, 6);
	ob2.setA(30.00);

	ob2.setH(6);

	ob2.print();

	cout << endl;

	cout << ob2.earnings();

	cout << endl;

	CommissionEmployee ob3("Minahal", "Fatima", "BITF21M515", 56.87, 12.34);
	ob3.setG(56.87);

	ob3.setC(12.34);

	ob3.print();

	cout << endl;

	cout << ob3.earnings();

	cout << endl;
	BasePlusCommisssionEmployee ob4("Minahal", "Fatima", "BITF21M515", 56.87, 12.34, 55.55);
	ob4.setG(56.87);
	ob4.setC(12.34);
	ob4.setB(55.55);
	ob4.print();

	cout << endl;

	cout << ob4.earnings();

	cout << endl;

	Employee* ptr[4];

	ptr[0] = new SalariedEmployee("Minahal", "Fatima", "BITF21M515", 30000);
	ptr[1] = new HourlyEmployee("Minahal", "Fatima", "BITF21M515", 30.00, 6);
	ptr[2] = new CommissionEmployee("Minahal", "Fatima", "BITF21M515", 56.87, 12.34);
	ptr[3] = new BasePlusCommisssionEmployee(ob4);
	
	for (int i = 0; i < 4; i++)
	{
		ptr[i]->print();
		ptr[i]->earnings();
		cout << endl;
	}
	
	for (int i = 0; i < 4; i++)
	{
		delete ptr[i];
	}
	return 0;
}