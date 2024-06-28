import numpy as np
import random

a = np.array([])
for i in range(4):
  for j in range(3):
    a = np.append(a, i+j)
b=a.reshape(2,len(a)//2)

print("array: ",b)                    #2.a

print("Reversed without for loop:",np.array(list(reversed(b))))       #2.b


print("Reversed with for loop:")
for i in range(len(b)-1,-1,-1):
  print(b[i])                           #2.b

print("sum: ",b.sum(axis=0))           #2.c

k=[b[i][i] for i in range(2)]
print("diagnol elements: ",k)           #2.d


print("2D array to 1D array: ",b.reshape(1,12))         #2.f
print("2D array to 3D array: ",b.reshape(3,12//3))      #2.f


print("Ascending: ",np.sort(b,axis=1))            #2.g
print("Descending: ",-(np.sort(-b,axis=1)))       #2.g