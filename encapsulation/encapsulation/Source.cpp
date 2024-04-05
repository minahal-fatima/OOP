#include<iostream>
using namespace std;
class Information
{
private:
	string name;
	string companyName;
	int age;
public:
	void setname(string nam)
	{
		name = nam;
	}
	string getname()
	{
		return name;
	}
	void setcompanyname(string company)
	{
		companyName= company;
	}
	string getcompanyname()
	{
		return companyName;
	}
	void setage(int Age)
	{
		if (Age >= 18)
		{
			age = Age;
		}
	}
	int getage()
	{
		return age;
	}
	void introducton()
	{
		cout << "Your name is " << name << endl;
		cout << "Your companyname is " << companyName << endl;
		cout << "Your age is " << age << endl;
	}
	Information(string nam, string company, int Age)
	{
		name = nam;
		companyName = company;
		age = Age;
	}
};
int main()
{
	Information emp1 = Information("Minahil", "Amazon", 19);
	emp1.introducton();
	emp1.setage(17);
	cout << emp1.getname() << " is " << emp1.getage()<<" years old." << endl;
	cout << emp1.getcompanyname() << " is the company in which she is working" << endl;
}