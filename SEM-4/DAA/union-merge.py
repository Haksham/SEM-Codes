list=[(1,2),(2,3),(4,5),(6,7),(5,6),(3,7)]
n=len(list)
rank=[0]*n
parent=[i for i in range(n)]

def findP(parent,i):
  if parent[i]==i:
    return i
  return findP(parent,parent[i])       # Dont use this code!!

def union(parent,rank,x,y):
  if rank[x] < rank[y]:
    parent[x] = parent[y]
  elif rank[x] > rank[y]:
    parent[y] = parent[x]
  else:
    parent[y] = parent[x]
    rank[x] += 1

for i in list:
  union(parent,rank,i[0],i[1])
print(parent)
print(rank)