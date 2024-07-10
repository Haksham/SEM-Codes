# 6

# a.	Write a python function binary Search () to read a sorted array and search for the key element. Display the appropriate messages.


def binSearch(arr,start,end,key):
    if(start<=end):
        mid = (start+end)//2
        if(arr[mid]==key):
            return mid+1
        elif(arr[mid]>key):
            return binSearch(arr,start,mid-1,key)
        else:
            return binSearch(arr,mid+1,end,key)
    else:
        return -1

n=int(input("Enter number of elements: "))
ls=[]
for i in range(n):
    num=int(input("Enter element: "))
    ls.append(num)
s=int(input("Enter element to search: "))
res=binSearch(ls, 0, len(ls)-1, s)
print("Element found at position", res)




#  b.	Write a python program to simulate saving account processing in a bank using constructors. Create Deposit and Withdraw with other member function and Check for Validation while withdrawing the amount. Raise the appropriate exceptions when depositing and withdrawing an incorrect amount. Display appropriate messages.

class bank:
    def __init__(self,amt):
        self.amt=amt
    def withdraw(self,x):
        try:
            if x>self.amt or x<=0:
                raise Exception("not possible!!")
            else:
                self.amt-=x
        finally:print("")
    def deposit(self,x):
        try:
            if x>0:
                self.amt+=x
            else:
                raise Exception("Cant be -ve")
        finally:print("")
b1=bank(200)
b1.withdraw(-22)
b1.deosit(-100)
b1.deposit(0)