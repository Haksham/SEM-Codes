#include"stdio.h"
void main()
{
    int n,a[100],i,s,first,mid,last;
    printf("Enter how many array u want: ");
    scanf("%d",&n);
    printf("Enter arrays:\n");
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
    printf("Enter item to be searched: ");
    scanf("%d",&s);
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