#include<iostream>
using namespace std;

//class Algebra
//{
//	int* ar;
//	int size;
//
//public:
//
//	Algebra()
//	{
//		size = 5;
//		ar = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			ar[i] = 0;
//		}
//	}
//	Algebra(int size)
//	{
//		this->size = size;
//		ar = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			ar[i] = 0;
//		}
//	}
//	~Algebra()
//	{
//		delete[]ar;
//	}
//
//	Algebra(const Algebra& obj)
//	{
//		size = obj.size;
//		ar = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			ar[i] = obj.ar[i];
//		}
//			
//	}
//	Algebra operator=(const Algebra& obj)
//	{
//		if (this != &obj)
//		{
//			if (size != obj.size)			//checking the sizes of both object's array
//			{
//				delete[]ar;
//				size = obj.size;
//				ar = new int[size];
//			}
//			for (int i = 0; i < size; i++)
//			{
//				ar[i] = obj.ar[i];
//			}
//		}
//		return *this;
//		
//	}
//	int& operator[](int value)
//	{
//		if (value >= 0 && value < size)
//		{
//			return ar[value];
//		}
//		cout << "Out of bond";
//	}
//	
//};
/*
template<class t>
t add(t v1, t v2)
{
	return v1 + v2;
}
template<class t>
t divide(t a, t b)
{
	return a / b;
}
template<class t1,class t2>
t1 add(t1 a, t2 b)
{
	return a + b;
}
template<class arrayType>
void printA(const arrayType ar[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << endl;
	}

}*/

template <class t>
class Algebra
{
	t a;
	t b;
public:
	Algebra()
	{
		a = b = 0;
	}
	Algebra(t a, t b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{

	}

	friend istream& operator>>(istream& in, Algebra& obj)
	{
		in >> obj.a;
		in >> obj.b;
		return in;
	}
	template<class t1>
	friend ostream& operator<<(ostream& print, const Algebra<t1>& obj);
};
template<class t1>
ostream& operator<<(ostream& print, const Algebra<t1>& obj)
{

}
template <class t>
void Algebra<t>::print()
{

}
int main()
{
	/*cout << add<int>(1, 1) << endl;;

	cout << divide<float>(20.00, 10.00) << endl;

	cout << add<int, float>(1, 2.1) << endl;*/

	//cout << add<int>(1, 2.1);//same as above
	

	
	return 0;
}