#include <iostream>
#include<cmath>

#define T char
#define SIZE 100

using namespace std;
int scobka_1 = 0;
int scobka_2 = 0;
int scobka_3 = 0;

T Stack[SIZE];

bool push(T data)
{
    if (scobka_1 < SIZE)
    {
        Stack[scobka_1] = data;
        return true;
    }
    else if (scobka_2 < SIZE)
    {
        Stack[scobka_2] = data;
        return true;
    }
    else if (scobka_3 < SIZE)
    {
        Stack[scobka_3] = data;
        return true;
    }
    else
    {
        cout << "Стек переполнен" << endl;
        return false;
    }

}

T pop()
{
    if (scobka_1 != 0)
    {
        return Stack[scobka_1];
    }
    else if (scobka_2 != 0)
    {
        return Stack[scobka_2];
    }
    else if (scobka_3 != 0)
    {
        return Stack[scobka_3];
    }
    else
    {
        cout << "Стек пуст " << endl;
        return 0;
    }
}





int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите кол-во элементов для проверки последовательности :" << endl;
    int size;

    cin >> size;
    char* brace = new char[size];
    cout << "Введите скобочную последовательность для проверки :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> brace[i];
    }

    if (brace[0] == '(')
    {
        push(brace[0]);
        scobka_1++;
    }
    else if (brace[0] == '{')
    {
        push(brace[0]);
        scobka_2++;
    }
    else if (brace[0] == '[')
    {
        push(brace[0]);
        scobka_3++;
    }

    for (int i = 1; i < size; i++)
    {
        if (brace[i] == '(')
        {
            push(brace[i]);
            scobka_1++;
        }
        else if (brace[i] == '{')
        {
            push(brace[i]);
            scobka_2++;
        }
        else if (brace[i] == '[')
        {
            push(brace[i]);
            scobka_3++;
        }

    }
    for (int i = 1; i < size; i++)
    {
        if (brace[i] == ')')
        {
            pop();
            scobka_1--;
        }
        else if (brace[i] == '}')
        {
            pop();
            scobka_2--;
        }
        else if (brace[i] == ']')
        {
            pop();
            scobka_3--;
        }




    }

    if (scobka_1 == 0 && scobka_2 == 0 && scobka_3 == 0)
    {
        cout << "Последовательность верна " << endl;
    }
    else
    {
        cout << "Последовательность не верна " << endl;
    }

    delete[] brace;

    return 0;
}


