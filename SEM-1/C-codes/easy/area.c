#include"stdio.h"
#define PI 3.1415
void main()
{
    float r,s,a;
    printf("radius of circle is:");
    scanf("%f",&r);
    s=PI*r*r;
    a=2*PI*r;
    printf("the area of circle is: %f\n",s);
    printf("circumference is: %f",a);
}