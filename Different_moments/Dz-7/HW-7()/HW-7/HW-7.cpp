#include"Hw-7.h"

#include<fstream>
#include<iterator>
#include<algorithm>
#include<sstream>

using namespace std;

static const auto FILEPATH("./data.bin");
static const auto STRING_SEP('\0');

template<typename T>
void value2Bin(ostream& output, T const & value)
{
    output.write(reinterpret_cast<const char*>(&value), streamsize(sizeof(value)));
}

void value2Bin(ostream& output, const string& value)
{
    output.write(reinterpret_cast<const char*>(value.c_str()), streamsize(sizeof(char)* value.size() + 1u));
}

template<typename T>
void bin2Value(istream& input, T& value)
{
    input.read(reinterpret_cast<char*>(&value), streamsize(sizeof(value)));
}
void bin2Value(istream& input, string& value)
{
    getline(input, value, STRING_SEP);
}

namespace Hw_7
{
    ostream& operator<<(ostream& output, const FullName& person)
    {
        value2Bin(output, person.surname);
        value2Bin(output, person.name);
        if (person.patronymic.has_value())
        {
            value2Bin(output, person.patronymic.value());
        }
        else
        {
            output << STRING_SEP;
        }
        return output;
    }

    istream& operator>>(istream& input, FullName& person)
    {
        bin2Value(input, person.surname);
        bin2Value(input, person.name);
        string patronymic;
        bin2Value(input, patronymic);
        if (patronymic.empty())
        {
            person.patronymic = nullopt;
        }
        else
        {
            person.patronymic = patronymic;
        }
        return input;
    }

    ostream& operator<<(ostream& ouptput, const Student& person)
    {
        ouptput << person.full_name;

        value2Bin(ouptput, person.scores.size());

        for_each(person.scores.cbegin(), person.scores.cend(), [&ouptput](const auto& value) {value2Bin(ouptput, value); });
        value2Bin(ouptput, person.average_score);
        return ouptput;
    }

    istream& operator>>(istream& input, Student& person)
    {
        input >> person.full_name;
        int score_size;
        bin2Value(input, score_size);
        person.scores.resize(score_size);
        for_each(person.scores.begin(), person.scores.end(), [&input](auto& value) {bin2Value(input, value); });
        bin2Value(input, person.average_score);
        return input;
    }

    StudentsGroup::StudentsGroup(const vector<Student> &students) : students_memb(students) {}

    void StudentsGroup::Open()
    {
        ifstream input(FILEPATH, ios::binary);
        Clear();
        if (input.is_open())
        {
            int students_size;
            bin2Value(input, students_size);
            students_memb.resize(students_size);
            for_each(students_memb.begin(), students_memb.end(), [&input](auto& element) {input >> element; });
            input.close();
        }
    }

    void StudentsGroup::Save()
    {
        ofstream output(FILEPATH, ios::binary);
        if (output.is_open())
        {
            value2Bin(output, students_memb.size());
            copy(students_memb.cbegin(), students_memb.cend(), ostream_iterator<Student>(output, " "));
            output.close();
        }
    }

    double StudentsGroup::GetAverageScore(const FullName& name) const
    {
        auto student{ Find(name) };
        return (nullptr == student ? 0. : student->average_score);
    }

    string StudentsGroup::GetAllInfo(const FullName& name) const
    {
        auto student{ Find(name) };
        ostringstream oss;
        if (student)
        {
            oss << "Surname : " << student->full_name.surname << endl;
            oss << "Name : " << student->full_name.name << endl;
            if (student->full_name.patronymic.has_value())
            {
                oss << "Patronymic : " << student->full_name.patronymic.value() << endl;
            }
            oss << "Scores : ";
            copy(student->scores.cbegin(), student->scores.cend(), ostream_iterator<unsigned>{oss, " , "});
            oss.seekp(-1, ios_base::end);
            oss << endl;
            oss << "Average score : " << student->average_score << endl;
        }
        return oss.str();
    }

    string StudentsGroup::GetAllInfo() const
    {
        ostringstream oss;
        for_each(students_memb.cbegin(), students_memb.cend(), [this, &oss](const auto& element) {
            oss << "-----------" << endl;
            oss << GetAllInfo(element.full_name); });
        return oss.str();
    }

    void StudentsGroup::Clear()
    {
        students_memb.clear();
    }

    const Student* StudentsGroup::Find(const FullName& name) const
    {
        auto res = find_if(students_memb.cbegin(), students_memb.cend(), [&name](const auto& element)->bool {
            return(element.full_name.surname == name.surname) &&
                (element.full_name.name == name.name) &&
                (element.full_name.patronymic == name.patronymic);
            });
        return (res != students_memb.cend() ? res.operator->() : nullptr);
    }

}

int main()
{
   
}


