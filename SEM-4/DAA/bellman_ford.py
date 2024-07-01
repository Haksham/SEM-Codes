G=[(3,2,6),(5,3,1),(0,1,5),(1,5,-3),(1,2,-2),(3,4,-2),(2,4,3)] # (u,v,weight) as directed graph(without -ve cycles)
# G=[(0,1,5),(1,2,1),(2,4,1),(1,3,2),(4,5,2),(4,3,-1),(5,4,-3)] # with -ve cycle
inf=999999
n=len(G)-1
dist=[inf]*n

root=0
dist[root]=0


def bellman(G,dist,n):
  l=[]
  for j in range(n):
    for i in G:
      if dist[i[0]]+i[2]<dist[i[1]]:
        dist[i[1]]=dist[i[0]]+i[2]
  f=0

  for i in G:      
    if dist[i[0]]+i[2]<dist[i[1]]:
      f=1
      break
  if f==1:
    print("-ve cycle detected!!")
  else:
    print(dist)

bellman(G,dist,n)