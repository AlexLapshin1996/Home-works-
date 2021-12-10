#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
  int i;
  for(i=2;i<n;i++)
  {
      if(n%i == 0 && i!=n)
        return 0;
  }
   return 1;
}

int main()
{
    int n;

    printf("Enter a number: ");

    scanf_s("%d",&n);

    printf("A number is :" "%d\n", isPrime(n));

    // 1 - prime
    // 0 - not prime

    return 0;
}
