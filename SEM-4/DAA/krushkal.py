# n=int(input("Enter number of vertices: "))
# e=int(input("Enter number of edges: "))
# G=[[0 for i in range(n)] for j in range(n)]
# for i in range(e):
#   print("Enter vertices(u,v):")
#   a=int(input())
#   b=int(input())
#   k=int(input("Enter wt: "))
#   G[a][b]=k
#   G[b][a]=k
# visited=[0 for i in range(n)]

def krushkal(G,visited,n):            # Dont use this code!!
  k=[]
  pair=[]
  sum=0
  for i in range(n):
    for j in range(n):
      if G[i][j] and  not i==j and [G[i][j],[j,i]] not in k:
        k.append([G[i][j],[i,j]])
  k=sorted(k,key=lambda x:x[0])
  print(k)

  N=[[0 for i in range(n)] for i in range(n)]
  for i in k:
    if i[1] not in pair:
      N[i[1][0]][i[1][1]]=i[0]
      N[i[1][1]][i[1][0]]=i[0]
      if check(N):
        pair.append((i[1]))
        sum+=i[0]
  print(pair)
  print(sum)

def check(G):
  n=len(G)
  visited=[0]*n
  for i in range(n):
    if not visited[i]:
      if DFS(G,i,visited,-1):
        return True
  return False

def DFS(G,i,visited,p):
  visited[i]=1
  for j in G[i]:
    if not visited[j]:
      if DFS(G,j,visited,i):
        return True
    elif p!=j:
      return True
  return False

G=[
  [0,10,6,5],
  [10,0,0,15],
  [6,0,0,4],
  [5,15,4,0]
]
visited=[0]*4
n=4
krushkal(G,visited,n)