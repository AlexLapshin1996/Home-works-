#include <iostream>
#include<ostream>
#include<fstream>
#include<sstream>
#include<string>
#include<tuple>
#include<optional>
#include<vector>
#include<algorithm>

using namespace std;

struct Person
{
public:
    Person() {}
    Person(string name)
    {
        this->name = name;
        surname = " ";
        patronymic = " ";
    }
    Person(string name, string surname) :Person(name)
    {
        this->surname = surname;
    }
    Person(string name,string surname,string patronymic) :Person(name, surname)
    {
        this->patronymic = patronymic;
    }
     
    friend bool operator <(const Person& per1,const Person &per2);
    friend bool operator ==(const Person& per1,const Person &per2);
    friend ostream& operator<<(ostream& out, const Person& per);
 
private:
    string name;
    string surname;
    optional<string>patronymic{nullopt};
};

bool operator < (const Person& per1, const Person& per2)
{
    return tie(per1.name, per1.surname, per1.patronymic) < tie(per2.name, per2.surname, per2.patronymic);
}

bool operator == (const Person & per1, const Person & per2)
{
    return tie(per1.name, per1.surname, per1.patronymic) == tie(per2.name, per2.surname, per2.patronymic);
}

ostream& operator<<(ostream& out, const Person& per)
{
    return out << per.name << " "<< per.surname << " "<< per.patronymic.value_or(" ") << " ";
}

struct PhoneNumber
{
    PhoneNumber():CodeCountry(0),CodeCity(0),Number(" "), AddNumber(nullopt) {}

    PhoneNumber(int CodeCounty, int CodeCity,string Number,optional<int> AddNumber) : CodeCountry(CodeCounty),CodeCity(CodeCity),Number(Number),AddNumber(AddNumber) {}
   
    friend bool operator < (const PhoneNumber &phn1,const PhoneNumber &phn2);

    friend bool operator ==(const PhoneNumber& phn1, const PhoneNumber& phn2);

    friend ostream& operator <<(ostream& out, const PhoneNumber& phn);
    
private:
    int CodeCountry;
    int CodeCity;
    string Number;
    optional<int> AddNumber;
    
};

bool operator<(const PhoneNumber& phn1, const PhoneNumber& phn2)
{
    return tie(phn1.CodeCountry, phn1.CodeCity, phn1.Number, phn1.AddNumber) < tie(phn2.CodeCountry, phn2.CodeCity, phn2.Number, phn2.AddNumber);
}

bool operator==(const PhoneNumber& phn1, const PhoneNumber& phn2)
{
    return tie(phn1.CodeCountry, phn1.CodeCity, phn1.Number, phn1.AddNumber) == tie(phn2.CodeCountry, phn2.CodeCity, phn2.Number, phn2.AddNumber);
}

ostream &operator<<(ostream& out, const PhoneNumber& phn)
{
    out << "+" << phn.CodeCountry << "(" << phn.CodeCity << ")" << phn.Number << " ";
    if (phn.AddNumber.has_value())
    {
        out << phn.AddNumber.value();
    }
    return out;
}

class PhoneBook
{
private:
    PhoneBook(ifstream &file)
    {
        if (!file.is_open())
        {
            cout << "Ошибка чтения" << endl;
        }

        string line;
        while (getline(file,line))
        {
            string Name_t, Surname_t, Patrynomic_t, Number_t, AddNumber_t;
            int CodeCounty_t, CodeCity_t;
            istringstream ss(line);
            ss >> Name_t >> Surname_t >> Patrynomic_t >> CodeCounty_t >> CodeCity_t >> Number_t >> AddNumber_t;
            optional<int> AddNumber_temp;

            if (Patrynomic_t=="-")
            {
                Patrynomic_t == "";
            }

            if (AddNumber_t=="-")
            {
                AddNumber_temp = nullopt;
            }
            else
            {
                AddNumber_temp = stoi(AddNumber_t);
            }
            data_numbers.push_back(make_pair(Person(Name_t, Surname_t, Patrynomic_t), PhoneNumber(CodeCounty_t, CodeCity_t, Number_t, AddNumber_new));
        }
        file.close();
    }
    void SortByName()
    {  
        sort(data_numbers.begin(), data_numbers.end(),
            [](const pair<Person, PhoneNumber>& pair1, const pair<Person, PhoneNumber>& pair2)
            {
                return pair1.first < pair2.first;
            }
        );
    }
    void SortByPhone()
    {
        sort(data_numbers.begin(), data_numbers.end(),
            [](const pair<Person, PhoneNumber>& pair1, const pair<Person, PhoneNumber>& pair2)
            {
                return pair1.second < pair2.second;
            }
        );
    }
    pair<bool, PhoneNumber> GetPhoneNumber(const string& find_surname)
    {
       
            for (const auto &[surname,number] : data_numbers)
            {
                if (surname == find_surname)
                {
                    return { true, number };
                }
                else
                {
                    return { false,number };
                }
            }
        
    }
    void ChangePhoneNumber(const Person& per, const PhoneNumber& phn)
    {
        auto find_person = [&per](const pair<Person, PhoneNumber>& pair1)
        {return pair1.first == per; };
        auto output = find_if(data_numbers.begin(), data_numbers.end(), find_person);
        if (output!=data_numbers.end())
        {
            output->second = phn;
        }
    }
    friend ostream& operator<<(ostream& out, const PhoneBook& PB)
    {
        for (auto n : PB.data_numbers)
        {
            out << n.first << " " << n.second << endl;
        }

        return out;
    }

private:
    vector < pair<Person, PhoneNumber>> data_numbers ;
};



int main()
{
    ifstream file("sourse/phonebook.txt");
    PhoneBook book(file);
    std::cout << book;

    


    return 0;
}
