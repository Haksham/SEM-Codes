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

def BFS(G,visited,s,n):
  queue=[]
  visited[s]=1
  print(s)
  queue.append(s)
  while len(queue)!=0:
    v=queue.pop()
    for j in range(n):
      if G[v][j] and visited[j]==0:
        visited[j]=1
        print(j)
        queue.append(j)

print(G)
BFS(G,visited,s,n)