a=float(input("side 1:"))
b=float(input("side 2:"))
c=float(input("side 3:"))
s=(a+b+c)/2
print(s)
a=(s*(s-a)*(s-b)*(s-c))**0.5
print("area of triangle is",a)


b=float(input("enter base:"))
h=float(input("enter height:"))
a=b*h/2
print("area of triangle is:",a)