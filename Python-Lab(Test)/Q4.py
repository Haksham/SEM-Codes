# 4.

# a.	Write a python program to initialize a dictionary of usernames and passwords associated with it.passwd={‘rahul’: ‘genius’, ‘kumar’:     #     ‘smart’, ‘ankita’: ‘intelligent’} perform the following functions:
# •	To print all the items in the dictionary.
# •	To print all the keys in the dictionary.
# •	To print all the values in the dictionary.
# •	To get the passwords of users. For example, passwd[‘rahul’]= genius
# •	e) Change the password of a particular user. For example, passwd[‘ankita’]=‘brilliant’


dictionary={"rahul":"genius", "kumar":"smart", "ankita":"intelligent"}
print(dictionary)
print(dictionary.keys())
print(dictionary.values())
name=input("Enter name: ")
print(dictionary.get(name))
name2=input("Enter name of which password has to be changed: ")
pwd=input("Enter new password : ")
dictionary.update({name2:pwd})
print(dictionary)



# a.	Develop a python program to count all the occurrences of vowels, consonants and digits from the given text using Regular expressions.

import re

text=input("Enter text: ")
vowels=re.findall('[aeiouAEIOU]',text)
digits=re.findall('\d', text)
alpha=re.findall('[a-zA-Z]',text)
print("Total vowel: ",len(vowels))
print("Total digits: ", len(digits))
print("Total number of consonants: ",len(alpha)-len(vowels))