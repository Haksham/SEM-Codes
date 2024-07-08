# 10.

# b.	Write a python program to demonstrate handling of the following exceptions using try and except.
# •	Name Error
# •	Index Error
# •	Key Error
# •	Zero Division Error

try:
    print(a)
except NameError:
    print("name error")
try:
    print(3//0)
except ZeroDivisionError:
    print("zero div")
try:
    i=[1,3,4]
    print(i[9])
except IndexError:
    print("index issue")
try:
    dic={'a':5,'b':6}
    print(dic['k'])
except KeyError:
    print("key issue")


# c.	Write a python program to read the Iris dataset and perform the following operations using Pandas
# •	Display first 5 rows of the dataset.
# •	Display last 5 rows of the dataset.
# •	Display the information about the dataset.
# •	Display the overview of the values of each column.
# •	Visualize the dataset using plot ().

import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv('iris.csv')

print(df.head())

print(df.tail())

print(df.info())

print(df.describe())

df.plot()
plt.show()