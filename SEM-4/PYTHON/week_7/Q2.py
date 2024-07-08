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