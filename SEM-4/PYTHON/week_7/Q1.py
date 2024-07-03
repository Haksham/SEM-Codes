try:
    print(a)
except NameError:
    print("name error")
try:
    print(3//0)
except ZeroDivisionError:
    print("zero div")
try:
    i=[1,3,4]
    print(i[9])
except IndexError:
    print("index issue")
try:
    dic={'a':5,'b':6}
    print(dic['k'])
except KeyError:
    print("key issue")