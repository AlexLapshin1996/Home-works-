#include <iostream>
#include<cstdint>

using namespace std;

class Power
{
private:
    int value1;
    int value2;

public:
    Power(int value1 = 5,int value2 = 4)
    {
        this->value1 = value1;
        this->value2 = value2;
    }

    void Set_Value(int value1, int value2)
    {
        this->value1 = value1;
        this->value2 = value2;
     
    }
    void calculate_values()
    {
        cout <<"Value = "<< pow(value1, value2) << endl;
    }

    ~Power()
    {

    };

};

class RGBA
{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;


public:
    RGBA()
    {
        this->m_red = 0;
        this->m_green = 0;
        this->m_blue = 0;
        this->m_alpha = 255;
    }

    RGBA(int m_red, int m_green, int m_blue, int m_alpha)
    {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
    }

    void print_RGBA()
    {
        cout << "M_red = " << static_cast<int>(m_red) << endl;
        cout << "M_green = " << static_cast<int>(m_green) << endl;
        cout << "M_blue = " << static_cast<int>(m_blue) << endl;
        cout << "M_alpha = " << static_cast<int>(m_alpha) << endl;
    }

    ~RGBA()
    {

    };

};

class STACK
{
private:

    int st[10];
    int lenght;

public:

    void reset()
    {
        lenght = 0;
        for (int i = 0; i < 10; ++i)
        {
            st[i] = 0;
        }
    }
    bool push(int value)
    {
        if (lenght == 10)
        {
            return false;
        }
        else
        {
            st[lenght++] = value;
            return true;
        }
        
    }
    int pop()
    {
        if (lenght == -1)
        {
            cout << "Стек пуст" << endl;
        }
        return st[--lenght];
    }

    void print()
    {
        cout << "(";
        for (int i = 0; i < lenght; ++i)
        {
            cout << st[i] << ' ';
            
        }
        cout << ")";
        cout << "\n";

    }
    
    ~STACK()
    {

    };

};

int main()
{
    setlocale(LC_ALL, "ru");
   
    Power one;
    one;
    one.calculate_values();

    cout << endl;

    RGBA two(20,40,60,200);
    two.print_RGBA();

    cout << endl;
    
    STACK st;
    st.reset();
    st.print();

    st.push(3);
    st.push(7);
    st.push(5);
    st.print();

    st.pop();
    st.print();

    st.pop();
    st.pop();
    st.print();

    return 0;
}


