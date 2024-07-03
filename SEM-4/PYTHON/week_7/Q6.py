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