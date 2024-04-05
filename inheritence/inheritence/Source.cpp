#include<iostream>
using namespace std;

class A
{
	int da;

public:

	A()
	{
		da = 0;
		cout << "A's default constructor.." << endl;
	}
	A(int da)
	{
		this->da = da;
		cout << "A's para constructor.." << endl;
	}
	A(const A& obj)
	{
		da = obj.da;
		cout << "A's Copy constructor.." << endl;
	}
	~A()
	{
		cout << "A's destructor.." << endl;
	}
	virtual void print()
	{
		cout << "A= " << da << endl;
	}
};
class B :public A
{
	int db;

public:

	B()
	{
		db= 0;
		cout << "B's default constructor.." << endl;
	}
	B(int da,int db):A(da)
	{
		this->db = db;
		cout << "B's para constructor.." << endl;
	}
	B(const B& obj):A(obj)
	{
		db = obj.db;
		cout << "B's Copy constructor.." << endl;
	}
	~B()
	{
		cout << "B's destructor.." << endl;
	}
	void print()
	{
		A::print();
		cout << "B= " << db << endl;
	}
};

int main()
{
	A oa;
	B ob(1, 2);
	oa = ob;
	oa.print();
	ob.print();

	return 0;
}
//class abstractInformation
//{
//	virtual void askForPromotion() = 0;
//};
//class Information
//{
//private:
//	int age;
//	int salary;
//protected:
//	string name;
//	string company;
//public:
//	void setname(string Name)
//	{
//		name = Name;
//	}
//	string getname()
//	{
//		return name;
//	}
//	void setcompanyname(string companyName)
//	{
//		company = companyName;
//	}
//	string getcompanyname()
//	{
//		return company;
//	}
//	void setage(int Age)
//	{
//		age = Age;
//	}
//	int getage()
//	{
//		return age;
//	}
//	void setsalary(int Salary)
//	{
//		salary = Salary;;
//	}
//	int getsalary()
//	{
//		return salary;
//	}
//	void introduceYourself()
//	{
//		cout << "Biodata of Employee" << endl << endl;
//		cout << "Your name is " << name << endl;
//		cout << "Your Companyname is " << company << endl;
//		cout << "Your age is " << age << endl;
//		cout << "Your salary is " << salary << endl << endl;
//	}
//	Information(string Name, string companyName,
//		int Age, int Salary)
//	{
//		name = Name;
//		company = companyName;
//		age = Age;
//		salary = Salary;
//	}
//	void askForpromotion()
//	{
//		if (age > 20)
//		{
//			cout << name << "---Congratulations you got promoted" << endl;
//		}
//		else
//		{
//			cout << name << "---Sorry you are not going to be promoted" << endl;
//		}
//	}
//	virtual void working()
//	{
//		cout << name << " is preparing a speech " <<  endl;
//	}
//};
//class developerInformation:public Information
//{
//public:
//	string favPfLanguage;
//	developerInformation(string Name, string companyName,
//		int Age, int Salary, string favPfLang)
//		:Information(Name, companyName, Age, Salary)
//	{
//		favPfLanguage = favPfLang;
//	}
//	void problemSolving()
//	{
//		cout << name << " is working in "
//			<< company << " and loves " << favPfLanguage << endl << endl;;
//	}
//	void working()
//	{
//		cout << name << " is writing a code of " << favPfLanguage << endl;
//	}
//};
//class teacher :public Information
//{
//public:
//	string subject;
//	void PreparedLesson()
//	{
//		cout << name << " is teaching " << subject <<" in "<<company<< endl;
//	}
//	teacher(string Name, string companyName,
//		int Age, int Salary, string Subject)
//		:Information(Name, companyName, Age, Salary)
//	{
//		subject = Subject;
//	}
//	void working()
//	{
//		cout << name << " is preparing a lesson of " << subject << endl;
//	}
//};
//int main()
//{
//	Information emp1 = Information("Minahil",
//		"Amazon", 19, 50000);
//	emp1.introduceYourself();
//	Information emp2 = Information("Salman",
//		"Devryx", 21, 70000);
//	emp2.introduceYourself();
//	emp1.askForpromotion();
//	emp2.askForpromotion();
//
//	developerInformation d = developerInformation("Minahil",
//		"Amazon", 19, 50000, "C");
//	d.problemSolving();
//
//	teacher t = teacher("Umair-Baber", "Pucit", 30, 80000, "OOP");
//	t.PreparedLesson();
//	/*d.working();
//	t.working();*/
//	Information* dev = &d;
//	Information* tec = &t;
//	dev->working();
//	tec->working();
//}