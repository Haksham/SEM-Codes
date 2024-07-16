#include<stdio.h>
typedef struct
{int hr,min,sec;
}clock;

void inc(clock *a);
void inc(clock *a)
{
    a->sec++;
    if(a->sec==60)
    {
        a->sec=0;
        a->min++;
        if(a->min==60)
        {
            a->min=0;
            a->hr++;
            if(a->hr==24)
            {a->hr=0;}
        }
    }
}

void show(clock *a);
void show(clock *a)
{
    printf("%d:%d:%d\n",a->hr,a->min,a->sec);
}
int main()
{
    clock a={11,58,50};
    int i;
    for(i=0;i<20;i++)
    {inc(&a);
    show(&a);}
}
