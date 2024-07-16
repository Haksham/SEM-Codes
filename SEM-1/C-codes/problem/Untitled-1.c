#include <stdio.h>
#include <conio.h>
int reverse(int n);
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(reverse(n)==n)
    {printf("palindrome");}
    else
    {printf("not");}
}
int reverse(int n)
{
    int r;
    static int s=0;
    if(n!=0)
    {
        r=n%10;
        s=s*10+r;
        reverse(n/10);}
    else
            return s;
    return s;
} 