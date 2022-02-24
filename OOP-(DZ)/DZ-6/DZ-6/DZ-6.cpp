#include <iostream>
#include<string>
#include<sstream>

using namespace std;

ostream& endll(ostream& a)
{
    a.write("\n\n", 2);
    a.clear();
    a.flush();
    return a;
}


int main()
{
    setlocale(LC_ALL, "ru");

    int value;
    string str;
    cout << "Введите число : ";
    while (getline(cin, str))
    {
        stringstream sline(str);
        if (sline >> value)
        {
            if (sline.eof())
            {
                break;
            }
        }
        cout << "Ошибка,попробуйте еще раз " << endl;
        cout << "Введите число : ";
    }

    cout << "Вы ввели : " << value<<endl;

    cout << "Проверка ENDLL : " << endll;
    cout << "О дивный,новый мир " << endl;

    return 0;
}

