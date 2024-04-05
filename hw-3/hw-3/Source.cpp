#include "iostream"

#include "fstream"

#include "string"

using namespace std;

int main()
{

    ifstream inf("studentt.txt");

    if (!inf)
    {
        cout << "File opening failed";
    }

    
    string records;

    getline(inf, records);

    while (getline(inf, records))
    {
         cout << records;
    }
    

    inf.close();

    return 0;
}