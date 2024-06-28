import numpy as np
import random
# n=int(input("Enter range: "))
n=12 #initialize as 12
a = np.array([])
for x in range(n):
    t=random.randint(0,20)
    a=np.append(a,t)
print("1.a  ->",a)                      #1.a


l=np.array([1,4,5,6,7])
p=np.array([2,6,8,5,12])
for i in l:
    for j in p:
        if i==j:
            print("1.b ->",j)           #1.b


print(a.shape,"\n")
print("1.c ->",a.reshape(2,6),"\n")                  #1.c
print("1.c ->",a.reshape(3,4),"\n")                  #1.c
print("1.d ->",a.reshape(3,2,2),"\n")                #1.d
print("1.e ->",a.reshape(2,int(n/2)),"\n")           #1.e
print("1.e ->",a.reshape(3,int(n/3)),"\n")           #1.e
print("1.e ->",a.reshape(4,int(n/4)))                #1.e



a=np.array([random.randint(-10,20) for i in range(5)])
b=np.array([random.randint(-10,20) for i in range(5)])
c=np.concatenate((a,b))
print("1.f ->",c)                                     #1.f
print("1.g -> Ascending: ",np.sort(c))                     #1.g
print("1.g -> descending: ",-(np.sort(-c)))                #1.g
print("1.g -> negative: ",np.sort(-c))                     #1.g
print("1.h -> Even: ",np.array([i for i in c if i%2==0]))        #1.h