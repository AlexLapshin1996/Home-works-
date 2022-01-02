#include "geek.h"

int bracesCheck(char* expression)
{
    const int TYPES = 3;
    char braces[][2]={{'(', ')'},{'[', ']'},{'{', '}'}};
    OneLinkList*st = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    int countIndex=0;
    while(*expression!='\0')
    {
        for (int i =0;i<TYPES;i++)
        {
            if(*expression==braces[i][0])
            {
                pushOneLinkStack(st,i);
            }
        }

        for (int i=0;i<TYPES;i++)
        {
            if(*expression==braces[i][1])
            {
                if(st->size==0)
                {
                    return countIndex;
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
        }
        expression++;
        countIndex++;
    }
    if( st->size!=0)
    {
        return st->head->dat;
    }
    return -1;
}

void copy_list(OneLinkList*from,OneLinkList*to)
{
    int size = from->size;
    OneLinkNode*current = from->head;
    while(size!=0)
    {
        for(int i=0;i<size-1;i++)
        {
            current=current->next;
        }
        pushOneLinkStack(to,current->dat);
        size--;
        current=from->head;
    }
}

boolean isSorted(OneLinkList*list)
{
    OneLinkNode *current = list->head;
    while(current->next !=NULL)
    {
        if(current->dat > current->next->dat)
        {
            return false;
        }
        current=current->next;
    }
    return true;
}


int main()
{
    printf(") : %d \n", bracesCheck(")"));
    printf(") : %d \n", bracesCheck("("));
    printf("{ ( [ {} [] () ] ) } : %d \n", bracesCheck("{ ( [ {} [] () ] ( }"));
    printf("[2*2{5/(2*5)}] : %d \n", bracesCheck("[2*2{5/(2*5)}]"));

    OneLinkList * first = (OneLinkList*) malloc(sizeof (OneLinkList));
    initOneLinkList(first);
    OneLinkList *second = (OneLinkList*) malloc(sizeof (OneLinkList));
    initOneLinkList(second);

    for (int i = 1; i < 9; i++)
    {
        pushOneLinkStack(first,i);
    }
    printOneLinkIntList(first);
    copy_list(first,second);
    printOneLinkIntList(second);
    printf("%s \n", isSorted(first) ? "true" : "false");
}
