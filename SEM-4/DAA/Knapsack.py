# ls=[(5,100),(7,300),(8,200),(10,100),(5,200),(2,100)]
ls=[(3,2),(4,3),(6,1),(5,4)]                # (weight , price)
ls=sorted(ls,key=lambda x:x[0])
items=[]
print(ls)
w=8
n=len(ls)
arr=[[0 for _ in range(w+1)] for _ in range(n+1)]


for i in range(n+1):
  for j in range(w+1):
    if ls[i-1][0]<=j:
      arr[i][j]=max(ls[i-1][1]+arr[i-1][j-ls[i-1][0]],arr[i-1][j])
    else:
      arr[i][j]=arr[i-1][j]

res=arr[n][w]

for i in range(n,0,-1):
    if arr[i][w]!=arr[i-1][w]:
        items.append(ls[i-1])
        w -= ls[i-1][0]


print(arr)
print("items are: ",items)
print("Total price: ",res)