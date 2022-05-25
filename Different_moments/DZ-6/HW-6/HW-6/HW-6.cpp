#include <iostream>
#include<thread>
#include<mutex>
#include<future>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<chrono>

using namespace std;

mutex m1;

void pcout(const int Thread_number)
{
    lock_guard m1_lock_guard(m1);
    cout << "This thread is : " << Thread_number << endl;
}

bool IsPrime(int value)
{
    if (value == 2)
    {
        return true;
    }
    if (value <2 || value %2 ==0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(value); i++)
    {
        if (value%i==0)
        {
            return false;
        }
    }
    return true;
}

int FindPrime(int n, int& count)
{
    int current = 0;
    while (count<n)
    {
        current++;
        if (IsPrime(current))
        {
            count++;
        }
    }
    return current;
}

int AsyncFindPrime(int n)
{
    int count = 0;
    future<int> prime_number = async(launch::async, FindPrime, n, ref(count));
    while (count*100/n < 100)
    {
        cout << count * 100 / n << " % " << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    return prime_number.get();
}

struct Item
{
    int member_id;
    int member_price;
    Item(int id,int price) : member_id(id),member_price(price) {}
};

bool operator < (const Item& left, const Item& right)
{
    return left.member_price < right.member_price;
}

mutex m2;
priority_queue<Item> house;
const int Number_items = 10;
bool th_end;

void Put()
{
    for (int i = 0; i < Number_items; i++)
    {
        this_thread::sleep_for(chrono::microseconds(1000));
        {
            lock_guard m2_lock_guard(m2);
            const pair<int, int> item{ i + 1,rand() % 10000};
            house.push(Item(item.first, item.second));
            cout << "Owner puts item : " << item.first << " with price :" << item.second << endl;
        }
        lock_guard m2_lock_guard(m2);
        th_end = true;
    }
}

void Steal()
{
    for (int i = 0; i < Number_items; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1500));
        {
            lock_guard m2_lock_guard(m2);
            house.pop();
            cout << "Thief steals items : " << house.top().member_id << " with prise" << house.top().member_price << endl;
        }
    }
}

int main()
{
    cout << "Task 1 : " << endl;
    thread thread_1(pcout, 1);
    thread_1.join();
    thread thread_2(pcout, 2);
    thread_2.join();

    cout << "Task 2 : " << endl;
    const auto prime_number = AsyncFindPrime(1000000);
    cout << "Prime number = " << prime_number << endl;

    cout << "Task 3 : " << endl;
    thread owner(Put);
    thread thief(Steal);
    owner.join();
    thief.join();

}

