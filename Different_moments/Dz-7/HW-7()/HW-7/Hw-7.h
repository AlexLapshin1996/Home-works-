#pragma once

#include<string>
#include<optional>
#include<vector>

using namespace std;

namespace Hw_7
{
	struct FullName;
	struct Student;
	class StudetsGroup;

	class IRepository
	{
	public:
		IRepository() = default;
		virtual ~IRepository() = default;

		virtual void Open() = 0;
		virtual void Save() = 0;
	};

	class IMethods
	{
	public:
		IMethods() = default;
		virtual ~IMethods() = default;

		virtual double GetAverageScore(const FullName& name) const = 0;
		virtual string GetAllInfo(const FullName& name) const = 0;
		virtual string GetAllInfo() const = 0;
	};

	struct FullName
	{
		string surname;
		string name;
		optional<string> patronymic;

		friend ostream& operator << (ostream& output, const FullName& person);
		friend istream& operator>>(istream& input, FullName& person);
	};

	struct Student
	{
		FullName full_name;
		vector<unsigned> scores;
		double average_score;

		friend ostream& operator<<(ostream& output, const Student& person);
		friend istream& operator>>(istream& input, Student& person);
	};

	class StudentsGroup :public IRepository,public IMethods
	{
	public:
		StudentsGroup(const vector<Student>& students = {});
		~StudentsGroup() = default;

		virtual void Open() override;
		virtual void Save() override;

		virtual double GetAverageScore(const FullName& name) const override;
		virtual string GetAllInfo(const FullName& name) const override;
		virtual string GetAllInfo() const override;

		void Clear();
		inline const int Size() const { return students_memb.size(); }
		const Student* Find(const FullName& name) const;

	private:
		vector<Student> students_memb;
	};

}
