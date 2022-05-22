#include <iostream>
#include<iterator>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<string>


using namespace std;

template<typename T>
void PrintUniqueWord(T begin, T end)
{
    set<string> uniques;
    copy(begin, end, inserter(uniques, uniques.end()));
    copy(uniques.begin(), uniques.end(), ostream_iterator<string>(cout, " "));
}

int main()
{
    cout << "Task 1 :" << endl;
    vector<string> words{ "cat","dog","popcorn","cat","mouse","fish" };
    PrintUniqueWord(words.begin(), words.end());

    cout << "Task 2 :" << endl;
    multimap<int, string> MM_str;
    string input_text;
    const string splitter = ".!?";
    cout << "Input text :";
    getline(cin, input_text);
    while (!input_text.empty())
    {
        const int position = input_text.find_first_of(splitter);
        string temp = input_text.substr(0, position);
        input_text.erase(0, position + 1);
        const auto key = count_if(temp.begin(), temp.end(), [](const char ch) {return isspace(ch); });
        MM_str.emplace(key, temp);
    }
    for_each (MM_str.begin(), MM_str.end(), [](const pair<int, string>& str) {cout << str.second << endl; });
    {

    }
  
}


