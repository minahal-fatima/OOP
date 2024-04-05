#include "iostream"

using namespace std;

class Collection
{
private:

	int* data;//holds an array of integers allocated dynamically

	int size;//represents the number of elements in the array

public:

	Collection(int size)
	{
		this->size = size;

		this->data = new int[this->size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = 0;
		}
	}

	Collection(int arr[], int size)
	{
		this->size = size;

		this->data = new int[this->size];

		for (int i = 0; i < size; i++)
		{
			data[i] = arr[i];
		}
	}

	Collection(const Collection& obj)
	{
		this->size = obj.size;

		this->data = new int[size];

		for (int i = 0; i < size;i++)
		{
			data[i] = obj.data[i];
		}
	}

	~Collection()
	{
		delete[]data;
	}

	int getSize() const
	{
		return this->size;
	}

	int setElement(int i, int k)const
	{
		if (i>0 && i<size)
		{
			data[i] = k;
		}
		else
		{
			cout << "out of index...";
		}

		return data[i];
	}

	int countElement(int key) const
	{
		int counter = 0;

		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
			{
				counter++;
			}
		}

		return counter;
	}

	Collection getSubCollection(int start_index, int end_index)
	{
		
		int x = 0;

		for (int i = start_index; i <= end_index; i++)
		{
			if (start_index > 0 && start_index < end_index && end_index <= size)
			{
				x++;
			}
		}

		Collection temp(x);

		int a = 0;

		for (int i = start_index; i <= end_index; i++)
		{
			if (start_index > 0 && start_index < end_index && end_index <= size)
			{
				temp.data[a] = data[i];
				a++;
			}

			else
			{
				temp.size = 0;
				temp.data = NULL;

			}
		}

		return temp;
	}

	Collection operator=(const Collection& obj)
	{
		if (this != &obj)
		{
			delete[] data;

			this->size = obj.size;

			this->data = new int[this->size];

			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
			
		}

		return *this;
	}

	Collection operator+(const Collection& obj)const
	{

		Collection temp(this->size);
		
		if (size != obj.size)
		{
			cout << "Collection have different sizes";
			temp.size = 0;
			temp.data = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			temp.data[i] = this->data[i] + obj.data[i];
		}

		return temp;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}

		int y = 99;
		
		cout << " Array index is out of Bound..." << endl;
		
		return y;

	}

	int operator[](int index)const
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		cout << "Array index is out of Bound..." << endl;

		return 99;
	}

	bool operator-()
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] > 0)
			{
				return false;
			}
		}

		return true;
	}

	friend ostream& operator<<(ostream&,const Collection&);

	friend istream& operator>>(istream&,Collection&);
};
ostream& operator<< (ostream& print, const Collection& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		print << obj.data[i] << endl;
	}

	return print;
}

istream& operator>>(istream& input,Collection& obj)
{
	
	for (int i = 0; i < obj.size; i++)
	{
		cout << "Enter elements: ";

		input >> obj.data[i];

		cout << endl;

	}

	return input;
}
int main()
{
	int ar1[6] = { 2,4,7,2,1,2 };

	int ar2[6] = { 3,9,0,6,4,9 };

	Collection col(ar1, 6);

	Collection col2(ar2, 6), col3(6);

	cout << "Count in array1: " << col.countElement(2) << endl << endl;

	cout << "Count in array2: " << col2.countElement(4) << endl << endl;

	Collection col1(ar1, 5);

	col1.setElement(4, 5);
	
	cout << "Setting element: " << col1 << endl;;
	
	col3 = col2.getSubCollection(1, 4);

	cout << "getSubCollection Function: " << col3 << endl << endl;

	col3 = col2.operator=(col);

	cout << "Assignment operator: " << col3 << endl;

	Collection col5(5);

	cin >> col5;//taking input from user

	cout << "Checking negative elements: " << col2.operator-() << endl;;

	cout << "addition operator+: " << col2.operator+(col) << endl ;

	//checking index 

	Collection col6(ar1, 3);

	cout << col6[1];

	cout << col6[6];

	return 0;
}