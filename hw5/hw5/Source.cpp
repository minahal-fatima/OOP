#include "iostream"

#include "fstream"

#include "string"

using namespace std;

int main()
{

    ofstream outf("studentt.txt");

    if (!outf)
    {
        cout << "File opening failed";
    }

    else
    {
        int rollNo;

        string firstName;

        string lastName;

        int marks;

        cout << "Enter roll No: ";
        cin >> rollNo;

        cout << "Enter first name: ";
        cin >> firstName;

        cout << "last name ";
        cin >> lastName;

        cout << "marks ";
        cin >> marks;

        outf << rollNo << " " << firstName << " " << lastName << " " << marks << endl;

        while (rollNo != -9999)
        {
            outf << rollNo << " " << firstName << " " << lastName << " " << marks << endl;

            cout << "Enter roll No: ";
            cin >> rollNo;

            if (rollNo == -9999)
            {
                break;
            }

            cout << "Enter first name: ";
            cin >> firstName;

            cout << "last name ";
            cin >> lastName;

            cout << "marks ";
            cin >> marks;



        }
    }

    outf.close();
	return 0;
}

	
		