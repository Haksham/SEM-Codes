# 9.		

# a.	Develop a python program read a dataset and perform the following using Pandas 
# •	Visualize the dataset using plot ().
# •	Draw the Scatter plot for the dataset on any column.
# •	Display the scatter plot with different colors.
# •	Draw the Histogram for the dataset on any column.


import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv('iris.csv')

df.plot()
plt.show()

df.plot(kind="scatter",x='sepal.length',y='petal.length')
plt.show()

x,y=df['petal.length'],df['sepal.length']
plt.scatter(x,y,c='red')
x,y=df['petal.width'],df['sepal.width']
plt.scatter(x,y,c='green')
plt.show()

df['sepal.length'].plot(kind='hist')
plt.show() 


# a.	Develop a python program to demonstrate handling multiple exceptions using try, except , else and finally block statements.

try:
    ls=[]
    for i in range(5):
       ls.append(i)
    try:
        b=i//0
    except ZeroDivisionError:
        print("zero div")
    try:
        print(b)
    except NameError:
        print("name error")
    try:
        print(ls[9])
    except IndexError:
        print("index issue")
except KeyError:
    print("key issue")
else:
    print("Else statement")
finally:
    print("Code end....")