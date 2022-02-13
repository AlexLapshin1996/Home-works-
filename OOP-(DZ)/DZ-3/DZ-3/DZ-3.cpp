#include <iostream>
#include<math.h>
#include<string>
#include<numeric>

using namespace std;

class Figure
{
 public:
	virtual void GetSquare() = 0;	
	virtual void area() = 0;

	~Figure()
	{}
};

class Parallelogram : public Figure
{
public:
	Parallelogram()
	{
		A = 0;		
		H = 0;
	}

	Parallelogram(int A,int H)
	{
		this->A = A;
		this->H = H;
	}

	void area() override
	{
		S = A * H;
	}

	void GetSquare() override
	{
		cout << "Площадь параллелограмма равна - " << S << endl;
	}

	~Parallelogram()
	{}

protected:
	int S;
	int A;
	int H;	
};

class Circle : public Figure
{
	
public:
	Circle(double r)
	{
		this->r = r;
	}

	void area() override
	{
		S = pow(r,2) * pi;
	}
	void GetSquare() override
	{
		cout <<"Площадь круга равна - "<<S<<endl;
	}

	~Circle()
	{}

protected:
	double S;
	double r;
	const double pi = 3.14;
};

class Rectangle : virtual public Parallelogram
{
public:
	Rectangle(int a,int b) 

	{
		this->a = a;
		this->b = b;
	}
	void area() override
	{
		S = (a + b) * 2;
	}

	void GetSquare() override
	{
		cout << "Площадь прямоугольника равна - " << S << endl;
	}

	~Rectangle()
	{}

protected:
	int S;
	int a;
	int b;
};

class Square : virtual public Parallelogram
{
public:

	Square(int a)
	{
		this->a = a;
		
	}

	void area() override
	{
		S = a * a;
	}

	void GetSquare() override
	{
		cout << "Площадь квадрата равна - " << S << endl;
	}

	~Square()
	{}

protected:
	int S;
	int a;
};

class Rhombus : virtual public Parallelogram
{
public:
	Rhombus(int D,int H)
	{
		this->D = D;
		this->H = H;
	}

	void area() override
	{
		S = D * H;
	}
	void GetSquare() override
	{
		cout << "Площадь ромба равна - " << S << endl;
	}

	~Rhombus()
	{}

protected:
	int S;
	int D;
	int H;
	
};

class Car
{
protected:
	string company;
	string model;

public:
	Car()
	{
		company = "машина";
		model = "обычная";
		cout << __FUNCTION__ << endl;
	}

	void ShowInfo()
	{
		cout << company<<"\t"<< model <<"\t"<<endl;
		cout << endl;
	}

	~Car()
	{}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar()
	{
		company = "Lada";
		model = "Vesta";
		cout << __FUNCTION__ << endl;
	}

	void ShowInfo()
	{	
		cout << company << "\t" << model << "\t" << endl;
		cout << endl;
	}

	~PassengerCar()
	{

	}
};

class Bus : virtual public Car
{
public:
	Bus()
	{
		company = "Икарус";
		model = "Икар_01";
		cout << __FUNCTION__ << endl;
	}
	void ShowInfo()
	{	
		cout << company << "\t" << model << "\t" << endl;
		cout << endl;
	}

	~Bus()
	{

	}
};

class Minivan :  public PassengerCar, virtual  public Car
{
public:
	Minivan()
	{
		company = "VW";
		model = "Van";
		cout << __FUNCTION__ << endl;
	}

	void ShowInfo()
	{	
		cout << company << "\t" << model << "\t" << endl;
		cout << endl;
	}

	~Minivan()
	{

	}
};

class Fraction
{
private:
	int chislit;
	int znamenat;
public:

	Fraction() : Fraction(1, 5){}

	Fraction(int chislit, int znamenat)
	{
		SetChislit(chislit);
		SetZnamenat(znamenat);
	}
	Fraction(const Fraction& original)
	{
		SetChislit(original.chislit);
		SetZnamenat(original.znamenat);
	}

	void SetChislit(int chislit)
	{
		this->chislit = chislit;
	}

	void SetZnamenat(int znamenat)
	{
		if (znamenat ==0)
		{
			cout << "Denominator cannot be 0"<<endl;
		}
		else
		{
			this->znamenat = znamenat;
		}	
	}

	int GetChislit() const
	{
		return chislit;
	}

	int GetZnamenat() const
	{
		return znamenat;
	}

	void ShowFraction()
	{
		cout << GetChislit() << " / " << GetZnamenat() << endl;
	}

	friend Fraction operator +(const Fraction& one, const Fraction& two);
	friend Fraction operator -(const Fraction& one, const Fraction& two);
	friend Fraction operator *(const Fraction& one, const Fraction& two);
	friend Fraction operator /(const Fraction& one, const Fraction& two);
	friend bool operator >(const Fraction& one, const Fraction& two);
	friend bool operator <(const Fraction& one, const Fraction& two);
	friend bool operator ==(const Fraction& one, const Fraction& two);
	friend bool operator !=(const Fraction& one, const Fraction& two);
	friend bool operator >=(const Fraction& one, const Fraction& two);
	friend bool operator <= (const Fraction & one, const Fraction & two);

	Fraction operator -() const
	{
		return Fraction(-chislit, znamenat);
	}
};

Fraction operator +(const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChislit(one.chislit * two.znamenat + two.chislit * one.znamenat);
	result.SetZnamenat(one.znamenat * two.znamenat);
	return result;
}

Fraction operator -(const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChislit(one.chislit * two.znamenat - two.chislit * one.znamenat);
	result.SetZnamenat(one.znamenat * two.znamenat);
	return result;
}

Fraction operator *(const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChislit(one.chislit * two.chislit);
	result.SetZnamenat(one.znamenat * two.znamenat);
	return result;
}

Fraction operator / (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChislit(one.chislit * two.znamenat);
	result.SetZnamenat(one.znamenat * two.chislit);
	return result;
}

bool operator > (const Fraction& one, const Fraction& two)
{
	return (one.chislit * two.znamenat > two.chislit * one.znamenat);
}

bool operator <(const Fraction& one, const Fraction& two)
{
	return(one.chislit * two.znamenat < two.chislit* one.znamenat);
}

bool operator ==(const Fraction& one, const Fraction& two)
{
	return (one.chislit * two.znamenat == two.chislit * one.znamenat);
}

bool operator !=(const Fraction& one, const Fraction& two)
{
	return !(one == two);
}

bool operator >=(const Fraction& one, const Fraction& two)
{
	return !(one < two);
}

bool operator <=(const Fraction& one, const Fraction& two)
{
	return !(one > two);
}

class Card
{
private:
	enum SUIT
	{
		Hearts,
		Spades,
		Diamonds,
		Clubs
	};

	enum CardMeaning
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack = 10,
		Queen = 10,
		King = 10
	
	};

	SUIT masti;
	CardMeaning znachenie;
	bool CardPosition = false;

public:
	Card(SUIT masti, CardMeaning znachenie) : masti(masti), znachenie(znachenie) {};

	void flip()
	{
		CardPosition == true;
	}

	int GetValue()
	{
		return znachenie;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Circle a(5);
	a.area();
	a.GetSquare();

	Parallelogram b(2, 3);
	b.area();
	b.GetSquare();
	
	Rectangle c(4, 8);
	c.area();
	c.GetSquare();

	Square d(4);
	d.area();
	d.GetSquare();

	Rhombus g(5, 5);
	g.area();
	g.GetSquare();

	cout << endl;

	Car a1;
	a1.ShowInfo();

	PassengerCar a2;
	a2.ShowInfo();

	Bus a3;
	a3.ShowInfo();

	Minivan a4;
	a4.ShowInfo();

	///как я понял конструкторы создаются последовательно,
	///от родительского класса,в дочерний,при чем больше наследований,тем больше конструкторов 
	
	Fraction drob1(12, 8);
	drob1.ShowFraction();

	Fraction drob2(12, 3);
	drob2.ShowFraction();

	if (drob1 != drob2)
	{ 
	   cout << "Fractions are not equal" << endl;
	}

	Fraction drob3(24, 16);

	drob2 = drob2 - drob3;
	drob3.ShowFraction();
	drob2.ShowFraction();

	if (drob1 == drob3)
	{
	   cout << "Fractions are equal" << endl;
	}

	drob1 = drob1 + drob2;
	drob1.ShowFraction();
	drob2.ShowFraction();
	if (drob1 > drob2)
	{ 
	   cout << "Left Fraction is greater" << endl;
	}

	drob2 = drob2 * drob3;
	drob1.ShowFraction();
	drob2.ShowFraction();

	if (drob1 <= drob2)
	{ 
	   cout << "Left Fraction is less or equal" << endl; 
	}

	drob2 = drob1 / drob3;
	drob1.ShowFraction();
	drob2.ShowFraction();

	if (drob1 >= drob2)
	{ 
       cout << "Left Fraction is greater or equal" << endl;
	}

	drob1 = -drob1;
	drob1.ShowFraction();
	drob2.ShowFraction();

	if (drob1 < drob2)
	{
	 cout << "Left Fraction is less" << endl; 
	}

}


