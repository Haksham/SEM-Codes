#include <stdio.h>
int main()
{
int s = 1;
char x;
while(s++)
{
	x = getchar();
	putchar(x);
}
return 0;
}
