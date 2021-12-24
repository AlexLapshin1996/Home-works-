#include <stdio.h>
#include <stdlib.h>
#define SZ 10

#define SIZE 100

typedef struct
{
    int pr;
    int dat;
}Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init()
{
    for(int i = 0;i<SZ;++i)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void insert(int pr,int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;
    if (items == 0)
    {
        arr[tail++] = node;
        items++;
    }
    else if(items==SZ)
    {
        printf("%s \n","Queue is full");
        return;
    }
    else
    {
        int i = 0;
        int idx = 0;
        Node *temp;
        for(i = head;i<tail;++i)
        {
            idx = i%SZ;
            if(arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx%SZ;
        i++;
        while(i<=tail)
        {
            idx = i%SZ;
            temp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = temp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

Node* rem()
{
   if(items==0)
   {
       return NULL;
   }
   else
   {
    int idx = head++ % SZ;
    Node*temp = arr[idx];
    arr[idx] = NULL;
    items--;
    return temp;
   }
}

void printQueue()
{
    printf("[ ");
    for (int i = 0;i<SZ;i++)
    {
        if(arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d,%d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

int stack[SIZE];
int top = -1;
int i,x;

void push(int x)
{
    ++top;
    stack[top] = x;
}

int pop()
{
    return stack[top];
}



int main()
{
    int n,remainder;
    int item;
    printf("Please enter a decimal: ");
    scanf("%d",&n);

    while(n!=0)
    {
        remainder = n%2;
        n = n/2;
        push(remainder);
    }

     for(i=top;top>-1;top--)
     {
         item = pop();
         printf("%d",item);
     }

     printf("\n\n");

    init();
    insert(1,11);
    insert(3,22);
    insert(4,33);
    insert(2,44);
    insert(3,55);
    insert(4,66);
    insert(5,77);
    insert(1,88);
    insert(2,99);
    insert(6,100);
    printQueue();
     printf("\n");
    for(int i = 0;i<7;i++)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d\n",n->pr,n->dat);
    }
    printf("\n");
    printQueue();

    insert(1, 110);
    insert(3, 120);
    insert(6, 130);
    printf("\n");
    printQueue();
    printf("\n");

    for(int i = 0;i<5;i++)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d\n",n->pr,n->dat);
    }
    printf("\n");

    printQueue();


    return 0;
}
