#include <iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<ctime>
#include<cmath>
#include<iterator>
#include<numeric>


using namespace std;

template<typename T1, typename T2>
void insert_sorted(T1& _cont, T2 _vol) 
{
    auto iter = upper_bound(_cont.begin(), _cont.end(), _vol);
    _cont.emplace(iter, _vol);
}

template<typename T>
void PrintVector(const vector<T> &vect)
{
    for (auto it = vect.begin();it!=vect.end();it++)
    {
        cout << *it << "\t";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    vector<int> Vect1(10);
    generate(Vect1.begin(), Vect1.end(), []() {return rand() % 100; });
    sort(Vect1.begin(), Vect1.end());

    int insert_value = 5;
    cout << "Task 1" << endl;
    cout << "Вектор до добавления элемента :" << endl;
    PrintVector(Vect1);
    cout << endl << "Вектор после добавления элемента :"<<endl;
    insert_sorted(Vect1, insert_value);
    PrintVector(Vect1);

    cout <<"\nTask 2" << endl;
    int num = 100;
    float error = 0;
    vector<float> a(num);
    vector<int> b;
    generate(a.begin(), a.end(), []() {return static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / 100.0)); });
    cout << "\nVector a :\n";
    PrintVector(a);
    copy(a.begin(), a.end(), back_inserter(b));
    cout << "\nVector b :\n";
    PrintVector(b);
    error = accumulate(a.begin(), a.end(), 0.0, [](float x, float y) {return x + pow(y - static_cast<int>(y), 2); });
    cout << "\nОшибка цифрового сигнала : " << error << endl;

}

