# 3.
# a.	Create a dictionary for words and their meanings. Write functions to add a new entry (word: meaning), search for a particular word and retrieve meaning, given meaning find words with same meaning, remove an entry, display all words sorted alphabetically. [Program must be menu driven].


dict={"help":"assistance","hello":"greeting","world":"planet","Earth":"planet","python":"snake"}

def add():
  w=input("Enter the word : ")
  m=input("Enter the meaning : ")
  dict.update({w:m})

def search():
  w=input("Enter the word:")
  print("Meaning of ",w," is ",dict.get(w))

def meaning():
  m=input("Enter the meaning:")
  for i in dict:
    if dict[i]==m:
      print(i,end=", ")

def remove():
  w=input("Enter the word:")
  del dict[w]

def sort():
  print(sorted(dict.keys()))

x=int(input("1.Add\n2.Search\n3.Find meaning\n4.Remove\n5.Sort\n6.Exit\nEnter your choice: "))
while x!=6:
  if x==1:
    add()
  elif x==2:
    search()
  elif x==3:
    meaning()
  elif x==4:
    remove()
  elif x==5:
    sort()
  else:
    print("Invalid choice")
  x=int(input("1.Add\n2.Search\n3.Find meaning\n4.Remove\n5.Sort\n6.Exit\nEnter your choice: "))


# b.	Write a python program to perform the following operations using user defined functions
# •	Display the maximum and minimum number from the array.
# •	Display the second largest number from the array without sorting


arr=[12,3,5,22,9,0,34,7,34,1,73,99,54]
print("Maximum number: ",max(arr))
print("Minimum number: ", min(arr))

maxs=max(arr)
max2=arr[0]
for i in range(len(arr)-1):
  if maxs>arr[i] and arr[i]>max2:
    max2=arr[i]
print("Second largest number: ", max2)