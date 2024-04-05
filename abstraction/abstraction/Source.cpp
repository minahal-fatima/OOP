#include<iostream>
using namespace std;
class abstractEmployee
{
	virtual void askForPromotion () = 0;
};
class Information
{
private:
	string name;
	string company;
	int age;
	int salary;
public:
	void setname(string Name)
	{
		name = Name;
	}
	string getname()
	{
		return name;
	}
	void setcompanyname(string companyName)
	{
		company = companyName;
	}
	string getcompanyname()
	{
		return company;
	}
	void setage(int Age)
	{
		age = Age;
	}
	int getage()
	{
		return age;
	}
	void setsalary(int Salary)
	{
		salary = Salary;;
	}
	int getsalary()
	{
		return salary;
	}
	void introduceYourself()
	{
		cout << "Biodata of Employee" << endl << endl;
		cout << "Your name is " << name << endl;
		cout << "Your Companyname is " << company << endl;
		cout << "Your age is " << age << endl;
		cout << "Your salary is " << salary << endl << endl;
	}
	Information(string Name, string companyName,
		int Age, int Salary)
	{
		name = Name;
		company = companyName;
		age = Age;
		salary = Salary;
	}
	void askForpromotion()
	{
		if (age > 20)
		{
			cout << name << "---Congratulations you got promoted" << endl;
		}
		else
		{
			cout << name << "---Sorry you are not going to be promoted" << endl;
		}
	}
};
int main()
{
	Information emp1 = Information("Minahil", 
						"Amazon", 19, 50000);
	emp1.introduceYourself();
	Information emp2 = Information("Salman",
						"Devryx", 21,70000);
	emp2.introduceYourself();

	emp1.askForpromotion();
	emp2.askForpromotion();
}