#include <iostream>
#include<cmath>

#define T char
#define SIZE 100

using namespace std;
int scobka_1 = 0;
int scobka_2 = 0;
int scobka_3 = 0;

T Stack[SIZE];

bool push(T data)
{
    if (scobka_1 < SIZE)
    {
        Stack[scobka_1] = data;
        return true;
    }
    else if (scobka_2 < SIZE)
    {
        Stack[scobka_2] = data;
        return true;
    }
    else if (scobka_3 < SIZE)
    {
        Stack[scobka_3] = data;
        return true;
    }
    else
    {
        cout << "Стек переполнен" << endl;
        return false;
    }

}

T pop()
{
    if (scobka_1 != 0)
    {
        return Stack[scobka_1];
    }
    else if (scobka_2 != 0)
    {
        return Stack[scobka_2];
    }
    else if (scobka_3 != 0)
    {
        return Stack[scobka_3];
    }
    else
    {
        cout << "Слишком много символов " << endl;
        return 0;
    }
}

void proverka(char*brace,int size)
{
    if (brace[0] == '(')
    {
        push(brace[0]);
        scobka_1++;
    }
    else if (brace[0] == '{')
    {
        push(brace[0]);
        scobka_2++;
    }
    else if (brace[0] == '[')
    {
        push(brace[0]);
        scobka_3++;
    }

    for (int i = 1; i < size; i++)
    {
        if (brace[i] == '(')
        {
            push(brace[i]);
            scobka_1++;
        }
        else if (brace[i] == '{')
        {
            push(brace[i]);
            scobka_2++;
        }
        else if (brace[i] == '[')
        {
            push(brace[i]);
            scobka_3++;
        }

        if (brace[i] == ')')
        {
            pop();
            scobka_1--;
        }
        else if (brace[i] == '}')
        {
            pop();
            scobka_2--;
        }
        else if (brace[i] == ']')
        {
            pop();
            scobka_3--;
        }

    }
}

void conclusion()
{
    if (scobka_1 == 0 && scobka_2 == 0 && scobka_3 == 0)
    {
        cout << "Последовательность верна " << endl;
    }
    else
    {
        cout << "Последовательность не верна " << endl;
    }
}

typedef struct Node
{
    T dat;
    struct Node* next;
}Node;

typedef struct 
{
    Node* head;
    int size;
}stek;

void init(stek* stack)
{
    stack->head = NULL;
    stack->size = 0;
}

bool push_2(stek* stack, T value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp==NULL)
    {
        cout << "Stack overflow" << endl;
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
    return true;
}

T pop_2(stek* stack)
{
    if (stack->size==0)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    Node* tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;   
}

void printOneLinkCharNode(Node* n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}

void printOneLinkCharStack(stek* stack)
{
    Node* current = stack->head;
    if (current==NULL)
    {
        printOneLinkCharNode(current);
    }
    else
    {
        do
        {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current!=NULL);
    }
    printf("Size : %d \n", stack->size);
}

void push_3(Node** head, int dat)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dat = dat;
    newNode->next = *head;
    *head = newNode;
}

struct Node* copyList(struct Node* head)
{
    struct Node* current = head;
    struct Node* newList = NULL;
    struct Node* tail = NULL;
    while (current!=NULL)
    {
        if (newList==NULL)
        {
            push_3(&newList, current->dat);
            tail = newList;
        }
        else
        {
            push_3(&(tail->next), current->dat);
            tail = tail->next;
        }
        current = current->next;
    }
    return newList;
}

void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d->", ptr->dat);
        ptr = ptr->next;
    }
    printf("Null");
}

int main()
{
    setlocale(LC_ALL, "ru");
    //task 1.
    cout << "Введите кол-во элементов для проверки последовательности :" << endl;
    int size;
    cin >> size;
    char* brace = new char[size];
    cout << "Введите скобочную последовательность для проверки :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> brace[i];
    }

    proverka(brace, size); 
    conclusion();
    delete[] brace;

    cout << "\n\n";

    //task2.
    stek* st = (stek*)malloc(sizeof(stek));
    init(st);
    push_2(st,'a');
    push_2(st,'b');
    push_2(st,'c');
    push_2(st,'d');
    push_2(st,'e');
    printOneLinkCharStack(st);

    struct Node* head = NULL;
    struct Node* dup = copyList(head);
    printList(dup);
    //Я много вариантов нашел как написать эту функцию
    //,но нет ниодной похожей как с нашим примером 
    //я сначала подумал,что можно было бы через цикл пройтись по нашему стеку
    //и скопировать элементы по одному,но я не понял как это сдеать 
   
  

    return 0;
}


