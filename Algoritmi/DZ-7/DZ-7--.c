#include <iostream>
#include "DZ-7.h"

using namespace std;

void swap_i(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fillArr(int*arr,int size) 
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%20;
    }
}

void pritnArr(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<"\t";
    }
}

void quicksort(int *arr, int first, int last)
{
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do
    {
        while (arr[i] < x)i++;
        while (arr[j] > x)j--;

        if (i<=j)
        {
            swap_i(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i<=j);

    if (i<last)
    {
        quicksort(arr, i, last);
    }

    if (first<j)
    {
        quicksort(arr, first, j);
    }
}

void bucketSort(int *arr, int size )
{   
    const int max  = size;  
    const int b = 12;
    int buckets[b][max + 1];
       
    for (int i = 0; i < b; i++)
    {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000; digit*=10)
    {
        
        for (int i = 0; i < max; i++)
        {
            int d = (arr[i] / digit)%b;

            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
        }
        int idx = 0;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < buckets[i][max]; j++)
            {
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int size_1 = 10;
    int arr[size_1];

    

    cout << "Изначально заданный массив :" << endl;
    fillArr(arr, size_1);
    pritnArr(arr, size_1);

    cout << endl;
    cout << "Отсортированный массив : " << endl;
    quicksort(arr, 0, (size_1) - 1);
    pritnArr(arr, size_1);
    cout << "\n""\n" << endl;

   
    static const int size_2 = 12;
    int arr_2[size_2] = { 0,2,8,3,4,6,5,9,8,2,7,3 };
    cout << "Массив до блочной сортировки :" << endl;
    pritnArr(arr_2, size_2);
    cout << endl;
    
    cout << "Массив после блочной сортировки :" << endl;
    bucketSort(arr_2,size_2);
    pritnArr(arr_2, size_2);
}


