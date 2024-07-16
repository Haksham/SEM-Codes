n=input("enter your name:")
print(int(len(n)))
if len(n)>5:
    print("too long , go for a short one!")
elif len(n)<2:
    print("too short is that even a name!!!")
else :
    print("good name:-)")