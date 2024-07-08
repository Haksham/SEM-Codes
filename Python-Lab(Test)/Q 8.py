# 8

# a.	Develop a python program to read 20 random numbers. Display all the odd numbers from this list which are of length 2 and 4.

ls=[]
for i in range(5):
    n=int(input("Enter a number: "))
    ls.append(n)
print("Added list: ",ls)
print("Odd numbers with length 2 and 4 are: ")
for i in ls:
    if i%2!=0:
      if len(str(i))==2 or len(str(i))==4 :
        print(i, end="  ")


# b.	Develop a python program to create a text file and ask the user to enter 5-6 lines of text. Count the number of upper case, lower case and digits in the file. Display the details of the file.

