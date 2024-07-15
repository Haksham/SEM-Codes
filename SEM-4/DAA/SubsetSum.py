n=int(input("Enter number of elements: "))
set=[int(input()) for i in range(n)]
sum=int(input("Enter the sum: "))

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
  return arr

# def items(arr,set,sum):           # not required
#     res = []
#     i,j = len(set),sum
#     while i > 0 and j > 0:
#         if arr[i][j] != arr[i - 1][j]:
#             res.append(set[i - 1])
#             j -= set[i - 1]
#         i -= 1
#     return res

arr=subset(set,sum)
if arr[n][sum]:
  print("SubSet exist!")
else:
  print("Subset dont exist!")