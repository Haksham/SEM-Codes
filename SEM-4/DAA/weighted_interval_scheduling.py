list= [(1, 2, 50), (3, 5, 20),(6, 19, 100),(2, 10, 200)]  #(start, end , profit)
# list=[(1,4),(2,6),(5,8),(3,11),(9,15),(10,16)]
# list=[(1,4,1),(2,6,3),(5,9,1)]

list=sorted(list,key=lambda x:x[1])
print(list)
p=[0]*len(list)


def GetP(i):
  for j in range(i-1,-1,-1):
    if list[i][0]>=list[j][1]:
      p[i]=j+1
      break

for i in range(len(list)-1,0,-1):
  GetP(i)


x=len(list)
t=[0]*x
def weighted(x):
  if x==0:
    return 0
  elif t[x-1]:
      return t[x-1]
  else:
    t[x-1]=max(weighted(x-1),list[x-1][2]+weighted(p[x-1]))
    return t[x-1]

print(weighted(x))