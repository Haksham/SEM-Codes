# 7.

# a.	Develop a python program to create two classes called as Stack and Queue. Provide the necessary data members and methods to display the operations that can be performed on stacks and queues. Test for all type of conditions.








# b.	Write a python program to utilize NumPy and perform the following operations.
# •	Read and display a 2D Array.
# •	Display the array elements in the reverse order.
# •	Display all the elements of principal diagonal elements.
# •	Sort the 2D array in ascending and descending order


import numpy as np
import random

a = np.array([])
for i in range(4):
  for j in range(3):
    k=int(input("Enter element:"))
    a = np.append(a, k)
b=a.reshape(2,len(a)//2)

print("array: \n",b)

print("\nReversed without for loop:\n",np.array(list(reversed(b))))

k=[b[i][i] for i in range(2)]
print("\ndiagnol elements: \n",k,"\n")

print("Ascending: \n",np.sort(b,axis=1),"\n")
print("Descending: \n",-(np.sort(-b,axis=1)))