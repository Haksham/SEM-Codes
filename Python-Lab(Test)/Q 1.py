# 1.		

# a.	Write a python program to read 2 numbers from the keyboard and perform the basic arithmetic operations based on the choice.(1-Add, 2-Subtract, 3-Multiply, 4-Divide)

a=int(input("Enter 1st number: "))
b=int(input("Enter 2nd number: "))
c=int(input("Enter choice \n1: '+'\n2: '-'\n3: '*'\n4: '/'\n: "))
if c==1:
    print("Sum: ",a+b)
elif c==2:
    print("Subtraction: ",a-b)
elif c==3:
    print("Multiplication: ",a*b)
elif c==4:
    print("Division: ",a/b)
else:
    print("Invalid choice")

# b.	Write a python program to create a list of tuples having first element as the strings and the second element as the length of the string. Output the list of tuples sorted based on the length of the string.

l = ["Hello", "World", "Programming", "Python"]
ls=sorted([(x, len(x)) for x in l], key=lambda x: x[1])
print(ls)