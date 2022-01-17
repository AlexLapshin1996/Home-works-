#include "geek.h"
#include "stdlib.h"
#include "stdbool.h"
#include "locale.h"

void cesar_cipher(char str[],int shift)
{
    int i = 0;

    while (str[i]!='\0')
    {
        if(str[i] >= 'A' && str[i]<='Z')
        {
            char c = str[i]-'A';
            c+=shift;
            c=c%26;
            str[i] = c+'A';
        }
        i++;
    }
    printf("%s",str);

}

int main()

{
   char str[] = "HELLO,BRUTUS";

    cesar_cipher(str,4);

    return 0;
}
