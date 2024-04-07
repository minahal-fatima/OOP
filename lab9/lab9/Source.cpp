#include<iostream>

using namespace std;

template<class t>
class Array
{

	t* data;

	int size;

public:

	Array()
	{
		this->size = 5;

		this->data = new t[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Array(int size)
	{
		this->size = size;

		this->data = new t[this->size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = 0;
		}
	}

	Array(const Array& obj)
	{
		this->size = obj.size;

		this->data = new t[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}
	}

	~Array()
	{
		delete[] data;
	}

	int getSize()
	{
		return size;
	}

	int setElement(int i, t k)
	{
		if (i >= 0 && i < size)
		{
			data[i] = k;
		}

		else
		{
			cout << "OUT OF INDEX..";
		}

		return data[i];
	}

	int countElement(t key)
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

	Array operator=(const Array& obj)
	{
		if (this != &obj)
		{
			delete[] data;

			this->size = obj.size;

			this->data = new t[size];

			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}

		}

		return *this;
	}

	Array getSubArray(int start_index, int end_index)
	{
		int x = 0;

		for (int i = start_index; i < end_index; i++)
		{
			if (start_index > 0 && start_index < end_index && end_index <= size)
			{
				x++;
			}
		}

		Array temp(x);

		int a = 0;

		for (int i = start_index; i < end_index; i++)
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


	Array operator+(const Array& obj)
	{
		int x = size + obj.size;

		int c = 0;

		Array temp(x);

		for (int i = 0; i < size; i++)
		{
			temp.data[i] = data[i];
		}

		for (int i = 0; i < size; i++)
		{
			temp.data[size + 1] = obj.data[i];

			c++;

		}

		return temp;
	}

	bool operator==(Array& obj)
	{

		for (int i = 0; i < size; i++)
		{
			return ((size == obj.size) && (data[i] == obj.data[i]));
		}

	}

	t& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << "OUT OF INDEX..";

			t z = -1;

			return z;
		}
	}

	t operator[](int index)const
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}

		cout << "OUT OF INDEX..";

		return -1;
	}

	template<typename s1>

	friend ostream& operator<< (ostream& out, const Array<s1>& obj);

	template<typename s2>

	friend istream& operator>> (istream& input, Array<s2>& obj);

};

template<typename s1>
ostream& operator<< (ostream& out, const Array<s1>& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		out << obj.data[i] << endl;
	}

	return out;
}
template<typename s2>
istream& operator>> (istream& input, Array<s2>& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		cout << "Enter element " << i + 1 << endl;

		input >> obj.data[i];
	}

	return input;
}
int main()
{

	Array<int>obj1(6);

	Array<int>obj4(6);

	obj1.setElement(0, 3);

	obj1.setElement(1, 2);

	obj1.setElement(2, 3);

	cout << "Elements in obj1: " << obj1 << endl;

	cout << "Count in array one: " << obj1.countElement(2) << endl << endl;

	cout << "Sub array : " << obj1.getSubArray(1, 4) << endl;

	obj4.setElement(0, 9);

	obj4.setElement(1, 8);

	obj4.setElement(2, 8);

	cout << "Elements in obj4: " << obj4 << endl;

	cout << "Count in array two: " << obj4.countElement(8) << endl << endl;

	Array<float>obj2(6);

	obj2.setElement(1, 7.8);

	obj2.setElement(2, 4.6);

	obj2.setElement(4, 8.1);

	cout << "Elements in obj2: " << obj2 << endl;

	cout << "Count in array two: " << obj2.countElement(1.1) << endl << endl;

	cout << "Sub array : " << obj2.getSubArray(1, 4) << endl;
	Array<int> obj3 = obj1.operator+(obj4);

	cout << "Arithmetic operator  : " << obj3 << endl;

	cout << "Checking equality : " << obj1.operator==(obj4);

	return 0;
}
