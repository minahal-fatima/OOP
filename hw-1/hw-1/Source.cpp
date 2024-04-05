#include<iostream>

#include<string>

using namespace std;

class Employee
{
    string name;
    int id;
    string department;
    string position;

public:

    Employee(string nameOfEmployee, int idOfEmployee, string depOfEmployee, string positionOfEmployee)
    {
        name = nameOfEmployee;
        id = idOfEmployee;
        department = depOfEmployee;
        position = positionOfEmployee;
    }

    Employee(string name_Employee, int id_Employee)
    {
        name = name_Employee;
        id = id_Employee;
        department = " ";
        position = " ";
    }

    Employee() // default constructor
    {
        name = " ";
        id = 0;
        department = " ";
        position = " ";
    }

    Employee(const Employee& obj) //copy constructor
    {
        name = obj.name;
        id = obj.id;
        department = obj.department;
        position = obj.position;
    }

    ~Employee() // destructor
    {
        cout << "Destructor executed..." << endl;
    }

    //implementation of getter/setter

    void setName(string name_Emp)
    {
        name = name_Emp;
    }

    string getName()
    {
        return name;
    }

    void setId(int id_Emp)
    {
        id = id_Emp;
    }

    int getId()
    {
        return id;
    }

    void setDepartment(string dep_Emp)
    {
        department = dep_Emp;
    }

    string getDepartment()
    {
        return department;
    }

    void setPosition(string pos_Emp)
    {
        position = pos_Emp;
    }

    string getPosition()
    {
        return position;
    }

    //implementation of  member functions

    void setInfo(string name_Emp, int id_Emp, string dep_Emp, string pos_Emp)
    {
        name = name_Emp;
        id = id_Emp;
        department = dep_Emp;
        position = pos_Emp;
    }

    void getInfo()//for getting information
    {
        cout << "Enter Employee's name: ";
        getline(cin, name);

        cout << "Enter id_Number: ";
        cin >> id;

        cin.ignore();
        cout << "ENter department-Name of employee: ";
        getline(cin, department);

        cout << "Enter Job Title of employee: ";
        getline(cin, position);
    }

    void putInfo() //for displaying information
    {
        cout << name << "   \t" << id << "  \t\t" << department << "  \t\t" << position << endl;
    }

};

int main()
{
    Employee obj1(" ", 0, " ", " "), obj2(" ", 0, " ", " "), obj3(" ", 0, " ", " "),
        obj4(" ", 0, " ", " "), obj5(" ", 0, " ", " ");

    obj1.getInfo();

    obj2.getInfo();

    obj3.getInfo();

    obj4.getInfo();

    obj5.getInfo();

    obj1.putInfo();

    obj2.putInfo();

    obj3.putInfo();

    obj4.putInfo();

    obj5.putInfo();

    return 0;

}