#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define T char
#define size 100

int cursor = -1;
T stack[size];

bool push(T data)
{
    if(cursor<size)
    {
        stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("Stack is overflow");
    }
}

T pop()
{
    if(cursor!=-1)
    {
        return stack[cursor--];
    }
    else
    {
        printf("Stack is empty");
        return -1;
    }
}



int main()
{


    return 0;
}
