#pragma once
#include<algorithm>
#include<any>
#include<fstream>
#include<functional>
#include<iostream>
#include<iterator>
#include<optional>
#include<sstream>
#include<tuple>
#include<typeinfo>
#include<utility>
#include<variant>
#include<vector>

using namespace std;

struct Person
{
private:
	string Name_memb, Surname_memb;
	optional<string> Patronymic_memb;

public:
	Person(const string Name, const string Surname, optional<string> Patronymic) : Name_memb(Name), Surname_memb(Surname), Patronymic_memb(Patronymic) {}

	friend ostream& operator<<(ostream& out, const Person& pers);
	friend bool operator==(const Person& pers1, const Person& pers2);
	friend bool operator ==(const Person& pers, const string& str);
	friend bool operator <(const Person& pers1, const Person& pers2);
};

ostream& operator<<(ostream& out, const Person& pers)
{
	out << pers.Name_memb << " " << pers.Surname_memb << " ";
	if (pers.Patronymic_memb.has_value())
	{
		out << pers.Patronymic_memb.value() << endl;
	}
	return out;
}

bool operator == (const Person& pers1, const Person& pers2)
{
	return tie(pers1.Name_memb, pers1.Surname_memb, pers1.Patronymic_memb) == tie(pers2.Name_memb, pers2.Surname_memb, pers2.Patronymic_memb);
}

bool operator == (const Person& pers, const string& str)
{
	return pers.Surname_memb == str;
}

bool operator < (const Person& pers1, const Person& pers2)
{
	return tie(pers1.Name_memb, pers1.Surname_memb, pers1.Patronymic_memb) < tie(pers2.Name_memb, pers2.Surname_memb, pers2.Patronymic_memb);
}

struct PhoneNumber
{
private:
	int CodeCountry_memb, CityCode_memb;
	string Number_memb;
	optional<int> AddNumber_memb;
public:
	PhoneNumber()
	{
		CodeCountry_memb = 0;
		CityCode_memb = 0;
		AddNumber_memb = nullopt;
	}
	PhoneNumber(int CodeCountry, int CityCode, const string& Number, optional<int> AddNumber)
		: CodeCountry_memb(CodeCountry), CityCode_memb(CityCode), Number_memb(Number), AddNumber_memb(AddNumber) {}

	friend ostream& operator <<(ostream& out, const PhoneNumber& phone_numb);
	friend bool operator<(const PhoneNumber& PN1, const PhoneNumber& PN2);
};

bool operator <(const PhoneNumber& PN1, const PhoneNumber& PN2)
{
	return tie(PN1.CodeCountry_memb, PN1.CityCode_memb, PN1.Number_memb, PN1.AddNumber_memb) < tie(PN2.CodeCountry_memb, PN2.CityCode_memb, PN2.Number_memb, PN2.AddNumber_memb);
}

ostream& operator <<(ostream& out, const PhoneNumber& PN)
{
	out << "+" << PN.CodeCountry_memb << "(" << PN.CityCode_memb << ")" << PN.Number_memb << " ";
	if (PN.AddNumber_memb.has_value())
	{
		out << " " << PN.AddNumber_memb.value();
	}
	return out;
}

class PhoneBook
{
public:
	PhoneBook(istream& file)
	{
		string line;
		while (getline(file, line))
		{
			string Name_tmp, Surname_tmp, Patronymic_tmp, Number_tmp, AddNumber_tmp;
			uint16_t CodeCountry_tmp, CodeCity_tmp;
			istringstream iss(line);
			iss >> Name_tmp >> Surname_tmp >> Patronymic_tmp >> CodeCountry_tmp >> CodeCity_tmp >> Number_tmp >> AddNumber_tmp;
			optional<int> t_add_number;

			if (Patronymic_tmp == "-")
			{
				Patronymic_tmp = "";
			}

			if (AddNumber_tmp == "-")
			{
				t_add_number = nullopt;
			}
			else
			{
				t_add_number = stoi(AddNumber_tmp);
			}

			book.push_back(make_pair(Person(Name_tmp, Surname_tmp, Patronymic_tmp), PhoneNumber(CodeCountry_tmp, CodeCity_tmp, Number_tmp, t_add_number)));
		}
	}

	void SortByName()
	{
		sort(book.begin(), book.end(), [](const pair<Person, PhoneNumber>& Pair1, const pair<Person, PhoneNumber>& Pair2) {return Pair1.first < Pair2.first; });
	}

	void SortByPhone()
	{
		sort(book.begin(), book.end(), [](const pair<Person, PhoneNumber>& Pair1, const pair<Person, PhoneNumber>& Pair2) {return Pair1.second < Pair2.second; });
	}

	friend ostream& operator<<(ostream& out, const PhoneBook& PB);

	tuple <string, PhoneNumber> GetPhoneNumber(const string& Surname)
	{
		PhoneNumber PN;
		int counter = 0;

		auto find_surname = [Surname, &counter, &PN](const pair<Person, PhoneNumber>& Pair)
		{
			if (Pair.first == Surname)
			{
				counter++;
				PN = Pair.second;
			}
		};

		for_each(book.begin(), book.end(), find_surname);

		string output = "";
		if (!counter)
		{
			output = "not found";
		}
		else if (counter > 1)
		{
			output = "found more one";
		}
		return { output,PN };
	}

	void ChangePhoneNumber(const Person& pers, const PhoneNumber& PN)
	{
		auto find_person = [&pers](const pair<Person, PhoneNumber>& Pair)
		{
			return Pair.first == pers;
		};
		auto output = find_if(book.begin(), book.end(), find_person);
		if (output != book.end())
		{
			output->second = PN;
		}
	}

private:
	vector<pair<Person, PhoneNumber>> book;
};

ostream& operator<<(ostream& out, const PhoneBook& PB)
{
	for (auto [first, second] : PB.book)
	{
		cout << first << second << endl;
	}
	return out;
}