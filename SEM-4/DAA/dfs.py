n=int(input("Enter number of vertices: "))
e=int(input("Enter number of edges: "))
G=[[0 for i in range(n)] for j in range(n)]
for i in range(e):
  print("Enter vertices(u,v):")
  a=int(input())
  b=int(input())
  G[a][b]=1
  G[b][a]=1
s=int(input("Enter root: "))
visited=[0 for i in range(n)]


def DFS(G,visited,s,n):
  visited[s]=1
  print(s)
  for j in range(n):
    if G[s][j] and visited[j]==0:
      DFS(G,visited,j,n)

print(G)
