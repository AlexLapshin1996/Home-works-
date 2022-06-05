#include "pch.h"
#include"SourseForTestHW8.h"


TEST(class_PhoneBook, OutFile)
{
	ifstream file("PhoneBook.txt");
	
	ASSERT_NO_THROW(PhoneBook book(file));
	file.close();
}

TEST(class_PhoneBook, GetNumber)
{
	ifstream file("PhoneBook.txt");
	PhoneBook book(file);
	auto answer = book.GetPhoneNumber("Filonenko");
	EXPECT_TRUE("+7 375 38 6581230 -");
	file.close();
}
 
TEST(class_PhoneBook, ChangePhoneNumber)
{
	ifstream file("PhoneBook.txt");
	PhoneBook book(file);
	PhoneNumber PN{ 7,423,"456923",nullopt };
	Person P{ "Alex","Filonenko","Eduardovich" };

	ASSERT_NO_THROW(book.ChangePhoneNumber(P, PN));
	file.close();
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
