#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf jmpbuffer;
int globval = 1;

int main(void) {
    register int regval = 1;   
    volatile int volval = 1;    
    static int statval = 1;  

    printf("Before setjmp:\n");
    printf("globval = %d, statval = %d, regval = %d, volval = %d\n", globval, statval, regval, volval);

    if (setjmp(jmpbuffer) != 0) {
        printf("After longjmp:\n");
        printf("globval = %d, statval = %d, regval = %d, volval = %d\n", globval, statval, regval, volval);
        return 0;
    }
    globval = 10;
    statval = 10;
    regval = 10;
    volval = 10;

    longjmp(jmpbuffer, 1);
    return 0;
}

// gedit p1.c
// gcc p1.c
// ./a.out

// The output will show the values of globval, statval, regval, and volval before and after the longjmp call.