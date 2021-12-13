#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define size_x  8
#define size_y  8

// task 1.
int perevod(int chislo)
{
    if(chislo<0)
    {
    printf("%d","-");
    perevod(-chislo);
    }
     else if (chislo<2)
    {
        printf("%d",chislo);
        return;
    }
    else
    {
        perevod(chislo/2);
        int result = chislo%2;
        printf("%d",result);
    }


    return;
}

// task 2.
int power(int x,int y)
{
    if(y == 0) return 1;
    if (y == 1) return x;
    if(y%2!=0)
    {
        return x*power(x,(y-1));
    }
    else
    {
        x = power(x,y/2);
        return x*x;
    }
}

// task 3.
int power_x2 (int x,int y)
{
    if (y == 0) return 1;
    if(y%2==0)
    {
        return power_x2(x*x,y/2);
    }
    else
    {
        return x*power(x,y-1);
    }

}

//task 4.

int routes(int doska[size_x][size_y],int x,int y)
{
    if (x==0 && y ==0 || doska[x][y] ==1)
        return 0;
        else if (x ==0 || y ==0)
            return 1;
        else
        return routes(doska,x,y-1)+routes(doska,x-1,y);
}

int main()
{
    printf("Enter the number\n");
    int chislo;
    scanf_s("%d",&chislo);
    printf("(Des) = ");
    perevod(chislo);
    printf("(Dvoich)\n");

    printf("Enter the number to pow\n");
    int a;
    int b;

    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);

    printf("a^b =%d\n", power(a,b));

    printf("Enter the number to pow_x2\n");
    int osn;
    int step;

    printf("osnovanie = ");
    scanf("%d",&osn);
    printf("stepen = ");
    scanf("%d",&step);

    printf("a^b =%d\n", power_x2(osn,step));

    int doska[size_x][size_y];

    doska[1][1] = 1;
    doska[4][3] = 1;
    doska[5][7] = 1;

    for (int y = 0;y<size_y;y++)
    {
        for (int x=0;x<size_x;x++)
        {
            printf("%5d", routes(doska,x,y));
        }
        printf("\n");
    }


    return 0;
}
