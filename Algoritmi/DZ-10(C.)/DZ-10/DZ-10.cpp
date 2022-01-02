#include <iostream>
#include<cmath>
#include "geek.h"

#define T char
#define SIZE 100

using namespace std;

int bracesCheck(char* expression)
{
    const int TYPES = 3;
    char braces[][2] = { {'(',')'},{'[',']'},{'{','}'} };
    OneLinkList* st = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    int countIndex = 0;
    while (*expression!='\0')
    {
        for (int i = 0; i < TYPES; i++)
        {
            if (*expression==braces[i][0])
            {
                pushOneLinkStack(st, i);
            }
        }

        for (int i = 0; i < TYPES; i++)
        {
            if (*expression==braces[i][1])
            {
                if (st->size==0)
                {
                    return countIndex;
                }
            }
            if (i==st->head->dat)
            {
                popOneLinkStack(st);
            }
            else
            {
                return countIndex;
            }
        }
        expression++;
        countIndex++;
    }
    if (st->size!=0)
    {
        return st->head->dat;
        return -1;
    }
}

void copy_list(OneLinkList* from, OneLinkList* to)
{
    int size = from->size;
    OneLinkNode* current = from->head;
    while (size!=0)
    {
        for (int i = 0; i < size-1; i++)
        {
            current = current->next;
        }
        pushOneLinkStack(to, current->dat);
        size--;
        current = from->head;
    }
}

boolean isSorted(OneLinkList* list)
{
    OneLinkNode* current = list->head;
    while (current->next != NULL)
    {
        if (current->dat > current->next->dat)
        {
            return false;
            current = current->next;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << bracesCheck << endl;
    

  
   
  

    return 0;
}


