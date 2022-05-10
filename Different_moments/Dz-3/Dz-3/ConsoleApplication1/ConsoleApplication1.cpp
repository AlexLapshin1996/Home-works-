#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>


using namespace std;

template<typename T>
void PushToTheBack(list<T>& ls)
{
    auto iter = ls.begin();
    double result = 0;
    double counter = 0;
    while (iter!=ls.end())
    {
        result += *iter;
        counter++;
        iter = next(iter);
    }
    result /= counter;
    ls.push_back(result);
}

template<typename T,int Size>
class Matrix
{
public:
    Matrix()
    {
        if (Size < 2)
        {
            cout << "Неверный размер матрицы" << endl;
        }

        Matrix_m.resize(Size * Size);
        generate(begin(Matrix_m), end(Matrix_m), []() {return rand() % 30; });
    }

    void PrintMatrix() const
    {
        for (auto i = 0; i < Size; i++)
        {
            for (auto j = 0; j < Size; j++)
            {
                cout << Matrix_m[i * Size + j];
            }
            cout << endl;
        }
    }

    T Determinant() const
    {
        return Determinant_cross(Matrix_m, Size);
    }

private:
    vector<T> Matrix_m;
    T Determinant_cross(const vector<T>& vect, const int size) const
    {
        if (size==2)
        {
            return vect[0] * vect[3] - vect[1] * vect[2];
        }
        else
        {
            T det = 0;
            for (int j = 0; j < size; j++)
            {
                vector<T> cross;
                for (int i = 1; i < size; i++)
                {
                    for (int k = 0; k < size; k++)
                    {
                        if (k!=j)
                        {
                            cross.emplace_back(vect[i * size + k]);
                        }
                    }
                }
                if (j%2==0)
                {
                    det += vect[j] * Determinant_cross(cross, size - 1);
                }
                else
                {
                    det -= vect[j] * Determinant_cross(cross, size - 1);
                }
            }
            return det;
        }
    }
};

template<typename T>
class Iterator
{
public:
    Iterator(const T position = 0) : it(position) {}

    bool operator !=(const Iterator<T>& right) const { return it != right.it; }
    bool operator == (const Iterator<T>& right) const { return it == right.it; }
    Iterator& operator++() { it++; return *this; }
    T operator* () const { return it; }

private:
    T it;
};

template<typename T>
class InRange
{
public:
    InRange(T from,T to) : from_m(from),to_m(to) {}

    Iterator<T> begin() const { return Iterator<T>(from_m); }
    Iterator<T> end() const { return Iterator<T>(to_m); }

private:
    T from_m;
    T to_m;
};



int main()
{
    list<int> num{ 1,2,3,4,5,6,7 };
    for (auto it = num.begin();it!=num.end();it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    PushToTheBack(num);
    for (auto it = num.begin(); it != num.end(); it++)
    {
        cout << *it << "\t";
    }
    cout <<"\n\n";

    Matrix<int, 2> m2;
    m2.PrintMatrix();
    cout << "Determinant = " << m2.Determinant() << endl;

    Matrix<int, 4> m4;
    m2.PrintMatrix();
    cout << "Determinant = " << m4.Determinant() << endl;

    Matrix<int, 6> m6;
    m2.PrintMatrix();
    cout << "Determinant = " << m6.Determinant() << endl;
   
    for (auto i : InRange<int>{10,30})
    {
        cout << i << " ";
    }
    cout << endl;

    
}


