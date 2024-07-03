def Mysqrt(x):
    try:
        if x<0:
            raise Exception("Its -ve !!!/")
        return x**(1/2)
    finally:
        print("")
while(1):
    x=int(input("Enter value: "))
    print(Mysqrt(x))