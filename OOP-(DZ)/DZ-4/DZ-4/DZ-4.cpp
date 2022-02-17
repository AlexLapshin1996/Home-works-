#include <iostream>
#include<string>
#include<cassert>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class ArrayInt
{
private:
    int m_lenght;
    int* m_data;
public:

    ArrayInt() : m_lenght(0), m_data(nullptr){}

    ArrayInt(int lenght) : m_lenght(lenght)
    {
        assert(lenght >= 0);
        if (lenght > 0)
        {
            m_data = new int[lenght];
        }
        else
        {
            m_data = nullptr;
        }
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_lenght = 0;
    }

    int& operator [](int index)
    {
        assert(index >= 0 && index < m_lenght);
        return m_data[index];
    }

    void resize(int newLenght)
    {
        if (newLenght == m_lenght)
        {
            return;
        }

        if (newLenght <=0)
        {
            erase();
            return;
        }

        int* newData = new int[newLenght] ;
        int CopyElements = 0;
        if (newLenght > m_lenght)
        {
            CopyElements = m_lenght;
        }
        else
        {
            CopyElements = newLenght;
        }
        
        for (int i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }

        delete[] m_data;
        m_data = newData;
        m_lenght = newLenght;

        
    }

    void at(int index, int data)
    {
        if (index >= 0 && index < m_lenght)
        {
            m_data[index] = data;
        }
    }

    void push_back(int value)
    {
        int* newData = new int[m_lenght + 1] ;
        int CopyElements = m_lenght;
        for (int i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        newData[m_lenght] = value;
        delete[] m_data;
        m_data = newData;
        m_lenght++;
    }

    void pop_back()
    {
        m_lenght--;
        int* newData = new int[m_lenght];
        for (int i = 0; i < m_lenght; i++)
        {
            newData[i] = m_data[i];
        }

        delete[]m_data;
        m_data = newData;

    }

    void pop_front()
    {
        m_lenght--;
        int* newData = new int[m_lenght];
        for (int i = 0; i < m_lenght; i++)
        {
            newData[i] = m_data[i + 1];
        }

        delete[] m_data;
        m_data = newData;

    }

    void PrintArray()
    {   
        for (int i = 0; i < m_lenght; i++)
        {
            cout <<m_data[i]<<"\t";
        }
        cout << "\n\n";
    }

    void SortArray()
    {
        int temp;
        for (int i = 0; i < m_lenght-1; i++)
        {
            for (int j = 1; j < m_lenght-i-1; j++)
            {
                if (m_data[j] > m_data[j+1])
                {
                    temp = m_data[j];
                    m_data[j] = m_data[j + 1];
                    m_data[j + 1] = temp;
                }
            }
        }
    }

};

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

class Hand
{
private:

    vector<Card*> cards;

public:

    Hand()
    {};

    void add(Card* value)
    {      
        cards.push_back(value);
    }

    void clear()
    {
        cards.clear();
    }

    void GetValue()
    {

        cout << "Сумма очков с карт равна - " << endl;

        for (auto it = cards.begin(); it<cards.end();it++)
        {
            cout << *it << " " << "\t";
        }

        cout << "\n";
        cout << "Количество карт в руке:";
        cout<<cards.size()<<endl;
    }

};

vector<int> arr_un = { 2,2,4,4,6,8,8,10,12,12,14,14,16 };

    
int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Изначальный массив : " << endl;
    ArrayInt AA(6);
    AA[0] = 2;
    AA[1] = 7;
    AA[2] = 12;
    AA[3] = 4;
    AA[4] = 8;
    AA[5] = 3;
     
    AA.PrintArray();

    cout << "Массив после сортировки : " << endl;
    AA.SortArray();
    AA.PrintArray();

    cout << "Массив после удаления последнего элемента :" << endl;
    AA.pop_back();
    AA.PrintArray();

    AA.pop_back();
    AA.PrintArray();

    cout << "Массив после удаления первого элемента :" << endl;
    AA.pop_front();
    AA.PrintArray();

    cout << "==============================================="<<endl;

    cout << "Вектор чисел, до сортировки :" << endl;

    for (int i : arr_un)
    {
        cout << i << " " << "\t";
    }
    cout << "\n";

    sort(arr_un.begin(), arr_un.end());
    auto last = unique(arr_un.begin(), arr_un.end());
    arr_un.erase(last, arr_un.end());

    cout << "Уникальные значения вектора : " << endl;
   
    for (int i : arr_un)
    {
        cout << i <<" "<<"\t";
    }
    
    cout << "\n\n";
    cout << "Количество уникальных значений вектора равно : ";
    cout<<arr_un.size();
    cout << "\n\n";
    
}

