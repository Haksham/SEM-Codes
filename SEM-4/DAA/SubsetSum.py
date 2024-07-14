n=int(input("Enter number of elements: "))
set=[int(input()) for i in range(n)]
sum=int(input("ENter the sum: "))

def subset(set,sum):
  n=len(set)
  arr=[[0 for i in range(sum+1)] for _ in range(n+1)]

  for i in range(n+1):                    # main code starts here
    for j in range(sum+1):
      if j==0:
        arr[i][j]=1
      elif arr[i-1][j]==1 or set[i-1]>j:
        arr[i][j]=arr[i-1][j]
      else:
        arr[i][j]=arr[i-1][j-set[i-1]]
  return arr[n][j]

if subset(set,sum):
  print("SubSet exist!")
else:
  print("Subset dont exist!")