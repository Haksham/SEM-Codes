print("you will get only 3 chances to guess the no.")
n=9
c=0
while c<3:
    g=int(input('guess:'))
    c =+ 1
    if g==n:
        print("you win!")
        break
    elif g!=n:
        print("try try!")
else:
    print("fail")
