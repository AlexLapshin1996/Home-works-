#include <iostream>
#include<math.h>

using namespace std;

void swap_i(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_arr(int** arr, int v1, int v2)
{
    int* t = arr[v1];
    arr[v1] = arr[v2];
    arr[v2] = t;
}

void PrintArr(int** arr, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void BubbleSort(int** arr, int x, int y)
{
    int buf;
    for (int k = 0; k < x; k++) {
        for (int s = 0; s < y; s++) {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (arr[k][s] < arr[i][j]) {
                        buf = arr[k][s];
                        arr[k][s] = arr[i][j];
                        arr[i][j] = buf;
                    }
                }
            }
        }
    }
}

int TPK_alg()
{
    double inputs[11], check = 400, result;
    int i;

    cout<< "Алгорит ТПК " << endl;
    cout << "Пожалуйста введите 11 чисел :" << endl;

    for (int i = 0; i < 11; i++)
    {
        cin >> inputs[i];
    }

    cout << "Вычисление по формуле f(x) = |x|^0.5 + 5x^3 для заданных чисел :" << endl;

    for (int i = 10; i >=0 ; i--)
    {
        result = sqrt(fabs(inputs[i]) + 5 * pow(inputs[i], 3));
        cout << " = " << endl;

        if (result > check)
        {
            cout<<i<<" элемент " << "-Переполнение-" << endl;
        }
        else
        {
            cout <<i<<" элемент равен " << result << endl;
        }
    }
    return 0;
}



int main()
{
    setlocale(LC_ALL, "ru"); 
    TPK_alg();
    cout << endl;
  
    const int size_x = 3; 
    const int size_y = 3;
     
    int** parr = new int*[size_x];
    for (int i = 0; i < size_x; i++)
    {
        parr[i] = new int[size_y];
    }

    parr[0][0] = 1;
    parr[0][1] = 9;
    parr[0][2] = 2;
    parr[1][0] = 5;
    parr[1][1] = 7;
    parr[1][2] = 6;
    parr[2][0] = 4;
    parr[2][1] = 3;
    parr[2][2] = 8;

    // правильно написать указатель и инициализировать массив 
   //parr [size_x][size_y] = { {1,9,2},{5,7,6},{4,3,8} };
    



        cout << "Изначальный массив : "<<endl;
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            cout << parr[i][j]<<"\t";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Отсортированный массив :" << endl;

    BubbleSort(parr, size_x, size_y);

    PrintArr(parr, size_x, size_y);
    
  //  for (int i = 0; i < size_x; i++)
    //{
    //    for (int j = 0; j < size_y; j++)
      //  {
        //    cout << parr[i][j] << "\t";
        //}
        //cout << endl;
    //}
 

    for (int  i = 0; i < size_x; i++)
    {
        delete[] parr[i];
        parr[i] = nullptr;
    }
     
    delete[] parr;
    parr = nullptr;


    return 0;
}

