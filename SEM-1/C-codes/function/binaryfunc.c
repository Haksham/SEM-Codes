#include<stdio.h>
void bin();
void bin(int s)
{   int last,mid,first,n,a[100];
    printf("Enter number to be searched:-");
    first=0;
    last=n-1;
    mid=(first+last)/2;
    while(first<=last)
    {
        if(a[mid]<s)
        {first=mid+1;
        }
        else if(a[mid]==s)
        {printf("%d found at %d position.\n",s,mid+1);
        break;}
        else
        {last=mid-1;}
        mid=(first+last)/2;
    }
    if(first>last)
    {printf("Item not found.");}
}
