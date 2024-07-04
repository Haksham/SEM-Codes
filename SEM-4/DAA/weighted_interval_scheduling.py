#list= [(1, 2, 50), (3, 5, 20),(6, 19, 100),(2, 10, 200)]  #(start, end , profit)
# list=[(1,4),(2,6),(5,8),(3,11),(9,15),(10,16)]
# list=[(1,4,1),(2,6,3),(5,9,1)]
list=[(1,2,100),(2,5,200),(3,6,300),(4,8,400),(5,9,500),(6,10,100)]

list=sorted(list,key=lambda x:x[1])
print(list)

x=len(list)
p=[0]*x
t=[0]*x
select=[]

for i in range(len(list)-1,0,-1):     # To get p[] array
  for j in range(i-1,-1,-1):
    if list[i][0]>=list[j][1]:
      p[i]=j+1
      break


def weighted(x):        # Gives final weight sum
  if x==0:
    return 0
  elif t[x-1]:
      return t[x-1]
  else:
    t[x-1]=max(weighted(x-1),list[x-1][2]+weighted(p[x-1]))
    return t[x-1]
  

def nodes(k):                   # To get the selected nodes for weights
  if k<1:
    return
  i=k
  while i>1 and t[i-1]==t[i-2]:
    i-=1
  select.append((list[i-1][0],list[i-1][1]))
  nodes(p[i-1])

print("Sum:",weighted(x))
nodes(x)
print("nodes: ",select)