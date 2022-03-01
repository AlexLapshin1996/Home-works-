#include <iostream>
#include<limits>
#include<type_traits>
#include<string>

using namespace std;

template<typename T>
enable_if_t<!numeric_limits<T>::is_integer, T> div(T num, T denom)
{
	if (denom < numeric_limits<T>::epsilon())
	{
		throw string{ "DivisionByZero" };
	}
	return num / denom;
}

class Ex
{
public:

	Ex(double value) : x(value) {}

	string message() const 
	{
		return to_string(x);
	}

	~Ex(){}

private:

	double x;
};

class Bar
{
public:

	Bar() :y(0.0) {}

	void set(double a)
	{
		if (y+a >100.0)
		{
			throw Ex{ a * y };
		}
		y = a;
	}

	~Bar() {}

private:

	double y;
};





int main()
{
	cout << "Task 1." << endl;
	try
	{
		cout << "Correct variant : " <<div(1.0, 2.0)<<endl;
		div(1.0, 0.0);
	}
	catch (const string &ex)
	{
		cout << "Catch excepthion : " << ex << endl;
	}

	cout << "\nTask 2." << endl;

	Bar bar;
	int n;
	try
	{
		do
		{
			cout << "Enter a number :";
			cin.clear();
			cin >> n;
			bar.set(n);
		} while (0 !=n);
	}
	catch (const Ex &ex)
	{
		cout << "Catch exception : " << ex.message() << endl;
	}
   
}

