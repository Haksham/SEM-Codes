try:
    while(1):
        age=int(input("Enter age: "))
        if(age>1 and age<150):
            print("Eligible")
        elif(age<=0):
            raise Exception("age can't be -ve or zero")
            
        else:
            raise Exception("Not Alive!!")
            
finally:
    print("code end..")