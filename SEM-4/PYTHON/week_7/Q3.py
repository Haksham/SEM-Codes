ls=[]
try:
    s=0
    for i in range(5):
        k=input('Enter value: ')
        if k.isdigit():
            s+=i
        else:
            raise ValueError("Plz enter only digits!!")
        ls.append(k)
    print("Sum: ",s)
    print("Avg: ",s/5)

finally:
    print("code end..")