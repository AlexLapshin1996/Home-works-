#include "geek.h"
#include "stdlib.h"
#include "stdbool.h"
#include "locale.h"

static const int coins[]={50,10,5,2,1,-1};

unsigned int hash_functhion(char*str)
{
    unsigned int hash_sum=0;

    for (int i = 0; str[i]!='\0'; i++)
        hash_sum+=str[i];

    return hash_sum;
}

void pick_coin(int sum)
{
    if(sum<=0)
        return;
    for (int i = 0;coins[i] !=-1; i++)
    {
     if(sum-coins[i]>=0)
     {
         printf("%u",coins[i]);
         pick_coin(sum-coins[i]);
         break;
     }
    }
}

int main()

{
    setlocale(LC_ALL,"RUS");
    /// Задание 1.
   char* test_string[] = {"Hello,world","AAAA","","NULL","0066","Cheetos"};
    for (int i = 0;test_string[i]!=NULL; i++)
    {
        printf("Hash sum of '%s' : %u\n",test_string[i], hash_functhion(test_string[i]));
    }

    /// Задание 2
    /// почему не выводит итог в консоль,я пробовал в онлайн среде,все вывелось и все понятно,тут видимо опять беды с компилятором
    int test_sum[]={98,20,-1,123,1010};
    for (int i = 0;i<5 ; i++)
    {
        printf("\n%d: ",test_sum[i]);
        pick_coin(test_sum[i]);
    }


    return 0;
}
