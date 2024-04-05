#include<iostream>
using namespace std;
//by default constructor
//class Information
//{
//public:
//	string name;
//	string companyName;
//	int age;
//	void introduceYourself()
//	{
//		cout << "Your name is " << name << endl;
//		cout << "You are studying in " << companyName << endl;
//		cout << "Your age is " << age << endl;
//	}
//};
//int main()
//{
//	Information employee1;
//	employee1.name = "Minahil";
//	employee1.companyName = "PUCIT-Lahore";
//	employee1.age = 19;
//	employee1.introduceYourself();
//}

//by creating your own constructor
class Information
{
public:
	string name;
	string companyName;
	int age;
	void introduceYourself()
	{
		cout << "Your name is " << name << endl;
		cout << "You are studying in " << companyName << endl;
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
	Information employee1 = Information("Minahil",
							"Pucit", 19);
	employee1.introduceYourself();
	Information employee2 = Information("Salman",
		"Pucit", 24);
	employee2.introduceYourself();
}