#include <iostream>
#include<memory>

using namespace std;

class Date
{
public:
	Date(int a = 1, int b = 2,int c = 2000) : m_day(a),m_month(b),m_year(c){}

	void SetDate(int day, int month, int year)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}

	int GetDay()
	{
		return m_day;
	}

	int GetMonth()
	{
		return m_month;
	}

	int GetYear()
	{
		return m_year;
	}

	~Date()
	{}

	friend ostream& operator<<(ostream& out, const Date &date);

private:
	int m_day;
	int m_month;
	int m_year;

};


ostream& operator<<(ostream& out, const Date& date)
{
	out << "Date :" << date.m_day << "," << date.m_month << "," << date.m_year << endl;
	return out;
}

unique_ptr<Date>& isLatest(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
	if (d1->GetYear() > d2->GetYear())
	{
		return d1;
	}
	else if (d1->GetYear() < d2->GetYear())
	{
		return d2;
	}
	else if (d1->GetMonth() > d2->GetMonth())
	{
		return d1;
	}
	else if (d1->GetMonth() < d2->GetMonth())
	{
		return d2;
	}
	else if (d1->GetDay() > d2->GetDay())
	{
		return d1;
	}
	else
	{
		return d2;
	}
}

unique_ptr<Date>& swapDate(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
	d1.swap(d2);
	return d2;
}



int main()
{
	unique_ptr<Date> date(new Date());
	unique_ptr<Date> today(new Date());
	today->SetDate(26, 02, 2022);
	cout << "Date contains : " << *date << endl;
	cout << "Today is :" << *today << endl;
	date = move(today);
	if (date)
	{
		cout << *date << endl;
	}
	else
	{
		cout << "Date pointer is NULL" << endl;
	}

	if (today)
	{
		cout << *today << endl;
	}
	else
	{
		cout << "Today pointer is NULL" << endl;
	}


	unique_ptr<Date> date1(new Date(1, 1, 2002));
	unique_ptr<Date> date2(new Date(2, 2, 2022));
	cout << *isLatest(date1, date2);

	cout << *swapDate(date1, date2);

	return 0;
}

