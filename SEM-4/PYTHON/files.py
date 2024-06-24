import random
# Q.1

# fil=open("test.txt","w")
# name=input("Enter name:")
# usn=input("Enter usn:")
# fil.write(f"\nName: {name}")
# fil.write(f"\nUsn: {usn}")
# fil.close
# fil=open("test.txt","r")
# print(fil.read())

#Q.2,Q.3

# fil=open("test.txt","w")
# for i in range(3):
#   t=input(f"Enter {i+1} line: ")
#   fil.write(f"{t}\n")
# fil.close()
# fil=open("test.txt","r")
# c=0
# d=0
# s=0
# l=0
# u=0
# for i in fil.readlines():
#   for j in range(len(i)):
#     if i[j].isalpha():
#       c+=1
#     if i[j].isdigit():
#       d+=1
#     if i[j].isspace():
#       s+=1
#     if i[j].isupper():
#       u+=1
#     if i[j].islower():
#       l+=1
# print("Char: ",c)
# print("Digits: ",d)
# print("Spaces: ",s) #subtract number of lines
# print("Lower char: ",l)
# print("Upper char: ",u)

#Q.7

f1=open("t1.txt","w")
f2=open("t2.txt","w")
l1=[random.randint(0,100) for i in range(6)]
l2=[random.randint(0,100) for i in range(6)]
f1.write(str(l1))
f2.write(str(l2))
f1.close()
f2.close()

f1=open("t1.txt","r")
f2=open("t2.txt","r")
f3=open("t3.txt","w")
a=list(f1.read())
b=list(f2.read())
x=[eval(i) for i in a if i.isdigit()]
y=[eval(i) for i in b if i.isdigit()]
print("file 1: ",x)
print("file 2: ",y)

l3=sorted(x+y)
f3.write(str(l3))
f3.close()
f3=open("t3.txt","r")
print(f3.read())