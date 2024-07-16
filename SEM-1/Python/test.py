import keyword
print(keyword.kwlist)



a,b,c=1,2,3
a,b,c=c,a,b
print("a=",a,"b=",b,"c=",c)



eid=int(input("Enter Employee ID"))
ename=input("Enter Employee name")
esal=int(input("Enter Empoloyee Salary"))
print("Emp id=%d Emp name=%s Emp sal=%g"%(eid,ename,esal))
print("Emp id:{} Emp name:{} Emp sal:{}".format(eid,ename,esal))
print("Emp id:{0} Emp name:{1} Emp sal:{2}".format(eid,ename,esal))
print ("Emp id={0} \nEmp name={1} \nEmpsal={2}".format(eid,ename,esal))



i = 25
if (i < 15):
    print("{} is smaller than 15".format(i))
    print("i'm in if Block")
else:
    print("{} is greater than 15".format(i))
    print("i'm in else Block")
print("i'm not in if and not in else Block")



x=range(2,6)
for i in x:
    print(i)
print()
for i in range(2,9,2):
    print(i)



def find_square(num):
    result = num * num
    return result
square = find_square(3)
print('Square:',square)

