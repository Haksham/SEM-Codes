print('''Welcome to car game
instructions are- help,start, stop, quit''')
n=""
started=False
while True:
    n = input("> ").lower()
    if n=="start":
        if started:
            print("car is already started!!!")
        else:
            started=True
            print("car started.....")
    elif n=="help":
        print("start - to start the car")
        print("stop - to stop the car")
        print("quit - to exit program")
    elif n=="stop":
        if not started:
            print("car is atready stopped.")
        else:
            started= False
            print("car is stopped!!!!!!")
    elif n=="quit":
        break
    else:
        print("I dont understand :-{(")