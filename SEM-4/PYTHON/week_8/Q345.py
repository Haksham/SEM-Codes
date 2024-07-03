import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv('iris.csv')

print(df.head())                #3.a
print(df.tail())                #3.b
print(df.info())                #3.c
print(df.describe())            #3.d

print(df.dropna())              #4.a
print(df.fillna(df.mean()))     #4.b
print(df.fillna(df.median()))   #4.c
print(df.duplicated())          #4.d

df.plot()                       #5.a
plt.show()                      #5.a

df.plot(kind="scatter",x='sepal.length',y='petal.length')  #5.b
plt.show()                                                 #5.b

x,y=df['petal.length'],df['sepal.length']      #5.c
plt.scatter(x,y,c='red')                       #5.c
x,y=df['petal.width'],df['sepal.width']        #5.c
plt.scatter(x,y,c='green')                     #5.c
plt.show()

df['sepal.length'].plot(kind='hist')           #5.d
plt.show()                                     #5.d