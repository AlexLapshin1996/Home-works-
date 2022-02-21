#include <iostream>
#include<assert.h>
#include<string>

using namespace std;

template <typename T>
class Pair1
{
private:

    T one;
    T two;

public:

    Pair1(T first, T second) : one(first),two(second)
    {  }

    
    T first()
    {
        return one;
    }

    T second()
    {
        return two;
    }

    const T& first( ) const
    {
        return one;
    }

    const T& second() const
    {
        return two;
    }

    ~Pair1()
    {

    }

};

template<typename D1,typename D2>
class Pair
{
public:
    Pair(D1 first,D2 second) : one(first),two(second)
    {}

    Pair()
    {}

    D1 first()
    {
        return one;
    }

    D2 second()
    {
        return two;
    }

    const D1& first() const
    {
        return one;
    }

    const D2& second() const
    {
        return two;
    }

    ~Pair()
    {}

private:
    D1 one;
    D2 two;

};

template<typename T,typename S = string>
class StringValuePair : public Pair<S,T>
{
public:
    StringValuePair(S first,T second) : one(first),two(second)
    {
        
    }

    string first()
    {
        return one;
    }

    T second()
    {
        return two;
    }

    ~StringValuePair()
    {}

private:
    string one;
    T two;

};



class GenericPlayer : public Hand
{
protected:
    string p_name;
    int total;
public:
    GenericPlayer(const string& name) : p_name(name) {}
    virtual bool isHitting() = 0;
    bool isBoosted()
    {
        if (total>=21)
        {
            return;
        }
    }
    void Bust()
    {
        cout << p_name << "bust" << endl;
    }
    

    ~GenericPlayer()
    {

    }

};






int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair : " <<p1.first() << ' ' << p1.second() << endl;

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair : "<<p2.first()<<' '<<p2.second()<<endl;

    cout << "\n";

    Pair<int, double> p3(6, 7.8);
    cout << "Pair :" << p3.first() << ' ' << p3.second() << endl;

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair : " << p4.first() << ' ' << p4.second() << endl;

    cout << "\n";

    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair : " << svp.first() << ' ' << svp.second() << endl;

    return 0;
}