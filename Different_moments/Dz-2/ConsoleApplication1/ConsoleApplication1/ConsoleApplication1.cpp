#include <iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<string>
#include<fstream>

using namespace std;

template<typename T>
T swap(T* ptr1, T* ptr2)
{
    T temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

template<typename T>
void SortPointers(vector<T*> &pointers)
{
    for (int i = 0; i < pointers.size(); i++)
    {
        for (int j = 0; j < pointers.size()-1; j++)
        {
            if (*pointers[j] > *pointers[j+1])
            {
                swap(*pointers[j],*pointers[j+1]);
            }
        }
    }
}

template<typename T>
void PrintVector(const vector<T*> &pointers)
{
    for (auto it : pointers)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void CounterIfFind(ifstream& file, int& counter)
{
    const string vowels("AEIOUYaeiouy");
    for ( string word;file >> word;)
    {
        counter += count_if(word.begin(), word.end(), [&vowels](const char& ch) {return vowels.find(ch) != string::npos;});
    }
}

void CounterIfFor(ifstream& file, int& counter)
{
    const string vowels("AEIUOYaeiuoy");
    for (string word; file>>word;)
    {
        counter += count_if(word.begin(), word.end(),
            [&vowels](const char& ch) { for (char vowel : vowels )
        {
            if (vowel == ch)
            {
                return true;
            }
            else
            {
                return false;
            }
        }}
            );
    }
}

void CounterForFind(ifstream& file, int& counter)
{
    const string vowels("AEIUOYaeiuoy");
    for (char ch;file.get(ch);)
    {
        const auto gotten = vowels.find(ch);
        if (gotten != string::npos)
        {
            counter++;
        }
    }
}

void CounterForFor(ifstream& file, int& counter)
{
    for (string word;file>>word;)
    {
        for (auto ch : word)
        {
            if (ch=='A' || ch == 'E' || ch == 'U' || ch == 'O' || ch == 'I' || ch == 'Y' || ch == 'a' || ch == 'e' || ch == 'u' || ch == 'o' || ch == 'i' || ch == 'y')
            {
                counter++;
            }
        }
    }
   
}

void PrintCounter(int& counter)
{
    cout << "Total vowels characters :" << counter << endl;
}

int main()
{
    int a = 10;
    int b = 5;
    int* ptrA = &a;
    int* ptrB = &b;

    cout << "A = " << a << " adress = " << ptrA <<" PtrA = " << *ptrA <<" adress ptrA = "<< ptrA<<endl;
    cout << "B = " << b << " adress = " << ptrB << " PtrB = " << *ptrB << " adress ptrB = " << ptrB << endl;

    swap(*ptrA, *ptrB);
    cout << endl;

    cout << "A = " << a << " adress = " << ptrA << " PtrA = " << *ptrA << " adress ptrA = " << ptrA << endl;
    cout << "B = " << b << " adress = " << ptrB << " PtrB = " << *ptrB << " adress ptrB = " << ptrB << endl;
    cout << "\n";

    cout << "Example vector--" << endl;
    const int Size = 10;
    vector<int*> pointers;

    for (int i = 0; i < Size; i++)
    {
        int* pointer = new int;
        *pointer = rand() % 50;
        pointers.push_back(pointer);
    }

    PrintVector(pointers);
    SortPointers(pointers);
    PrintVector(pointers);
    cout << endl;

    ifstream file("C:\\Users\\Alex\\Desktop\\Home-works-\\Different_moments\\Dz-2\\ConsoleApplication1\\data\\War and Peace.txt");
    if (file.is_open())
    {
        int vowel_counter = 0;       
        auto start1 = chrono::steady_clock::now();
        CounterIfFind(file, vowel_counter);
        auto end1 = chrono::steady_clock::now();
        chrono::duration<double> Time1 = end1 - start1;
        cout << " If and Find took time -" << Time1.count() * 1000 << "msec" << endl;
        PrintCounter(vowel_counter);
        file.close();

        vowel_counter = 0;
        file.open("C:\\Users\\Alex\\Desktop\\Home-works-\\Different_moments\\Dz-2\\ConsoleApplication1\\data\\War and Peace.txt");
        auto start2 = chrono::steady_clock::now();
        CounterIfFor(file, vowel_counter);
        auto end2 = chrono::steady_clock::now();
        chrono::duration<double> Time2 = end2 - start2;
        cout << " If and For took time -" << Time2.count() * 1000 << "msec" << endl;
        PrintCounter(vowel_counter);
        file.close();

        vowel_counter = 0;
        file.open("C:\\Users\\Alex\\Desktop\\Home-works-\\Different_moments\\Dz-2\\ConsoleApplication1\\data\\War and Peace.txt");
        auto start3 = chrono::steady_clock::now();
        CounterForFind(file, vowel_counter);
        auto end3 = chrono::steady_clock::now();
        chrono::duration<double> Time3 = end3 - start3;
        cout << " For and Find took time -" << Time3.count() * 1000 << "msec" << endl;
        PrintCounter(vowel_counter);
        file.close();

        vowel_counter = 0;
        file.open("C:\\Users\\Alex\\Desktop\\Home-works-\\Different_moments\\Dz-2\\ConsoleApplication1\\data\\War and Peace.txt");
        auto start4 = chrono::steady_clock::now();
        CounterForFor(file, vowel_counter);
        auto end4 = chrono::steady_clock::now();
        chrono::duration<double> Time4 = end4 - start4;
        cout << " For and For took time -" << Time4.count() * 1000 << "msec" << endl;
        PrintCounter(vowel_counter);
        file.close();

        
    }
    else
    {
        cout << "Error reading file" << endl;
    }

  

}

