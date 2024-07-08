# 5.

# b.	Write a python program to create a tuple and perform the following operations   
# •	Adding an items
# •	Displaying the length of the tuple
# •	Checking for an item in the tuple
# •	Accessing an items


tup=("one","two","three","four")
print(tup)

word=input("Enter a word to add: ")
tup=tup+(word,)
print(tup)

print("Length of tuple: ",len(tup))
w=input("Enter a word to search: ")
if w in tup:
  print("Word found")
else:
  print("Word not found")

i=int(input("Enter index of word to access: "))
print("Element of",i," index: ",tup[i])

# c.	Write a python program to create a text file and ask the user to enter 5-6 lines of text. Display the longest and the shortest word from the file. Display the length of these words.


file=open("file.txt", "w")
for i in range(5):
  text=input("Enter text: ")
  file.write(text+"\n")
file.close()

with open("file.txt", "r") as file:
  text=file.read()
  words=text.split()
  longest=max(words, key=len)
  shortest=min(words, key=len)
  print("Longest word: ",longest," with length ",len(longest))
  print("Shortest word: ",shortest," with length ",len(shortest))