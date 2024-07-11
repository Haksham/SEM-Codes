inf=99999
G=[                          # Dont use this code!!
  [0,4,4,0,0,0],
  [4,0,2,0,0,0],
  [4,2,0,3,1,6],
  [0,0,3,0,0,2],
  [0,0,1,0,0,3],
  [0,0,6,2,3,0]
]
n=6
dist=[inf]*n

def dijkstra(G,dist,n,root):
  heap=[]
  dist[root]=0
  for j in range(n):
    heap=sorted(heap,key=lambda x:x[0])      #sorting the heap
    heap.append([0,root])                    #[dist,node] and first node is [0,0] as assuming root is 0
    t=heap.pop(0)
    if G[t[1]][j]+t[0] < dist[j]:
      dist[j]=G[t[1]][j]+t[0]
      print(dist)
      heap.append([dist[j],j])
      heap.pop(0)

  print(dist) 
  print(heap)



print(dijkstra(G,dist,n,0))


# heap=[[5,2],[1,6],[9,0],[3,2],[4,9]]
# heap.append([0,0])
# print(heap)
# heap=sorted(heap,key=lambda x:x[0])
# print(heap)
# t=heap.pop(0)
# print(t)