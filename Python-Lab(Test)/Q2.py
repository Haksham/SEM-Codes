# 2.
# a.	Write a python program to display all the prime numbers in the given range.

u=int(input("Enter the upper limit : "))
l=int(input("Enter the lower limit : "))
ls=[]
for i in range(l,u+1):
    c=0
    for j in range(2,i):
        if i%j==0:
            c+=1
    if c==0:
        ls.append(i)
print("Prime numbers between", l, "and", u, "are:",ls)

# b.	Write a python program to create a list with all the subject names of the 4th semester and perform the following operations.
# •	Display the list using for loop.
# •	Display 2nd and 5th element of the list.
# •	Display first 4 elements of the list using the range of indexes.
# •	Display last 4 elements of the list using the range of negative indexes.
# •	Display if "Python Programming Lab" is available in the List or not.
# •	Demonstrate the working of append () and insert () function.
# •	Demonstrate the working of remove() and pop() function.

ls=["DAA","DCN","R","PY","MATH","MC-IOT"]
for i in ls:
    print(i, end="  ")

print("\n2nd Element:", ls[1],"\n5th Element: ",ls[5])
print("First 4 elements: ")
for i in range(0,4):
    print(ls[i], end="  ")
print("\nLast 4 elements: ")
for i in range(-4,0):
    print(ls[i], end="  ")

if "Python Programming Lab" in ls:
    print("\nPython Programming Lab is present in the list\n")
else:
    print("\nPython Programming Lab is not present in the list\n")

ls.append("Java")
print("List after appending Java: ", ls)

ls.insert(4,"C")
print("List after inserting C at 4th position: ", ls)

ls.remove("R")
print("List after removing R: ", ls)

ls.pop()
print("List after popping the last element: ", ls)