# G=[[0,4,4,0,0,0],
#   [4,0,2,0,0,0],
#   [4,2,0,3,1,6],
#   [0,0,3,0,2,0],
#   [0,0,1,2,0,3],
#   [0,0,6,0,3,0]]

G=[[0, 4, 0, 0, 0, 0, 0, 8, 0],
  [4, 0, 8, 0, 0, 0, 0, 11, 0],
  [0, 8, 0, 7, 0, 4, 0, 0, 2],
  [0, 0, 7, 0, 9, 14, 0, 0, 0],
  [0, 0, 0, 9, 0, 10, 0, 0, 0],
  [0, 0, 4, 14, 10, 0, 2, 0, 0],
  [0, 0, 0, 0, 0, 2, 0, 1, 6],
  [8, 11, 0, 0, 0, 0, 1, 0, 7],
  [0, 0, 2, 0, 0, 0, 6, 7, 0]
  ]

def dijkstra(G,root):
  n=len(G)                    # main code
  dist=[99999]*n
  dist[root]=0

  for _ in range(n):
    for i in range(n):
      for j in range(n):
        if G[i][j] and dist[i]+G[i][j]<=dist[j]:
          dist[j]=dist[i]+G[i][j]

  return dist

print(dijkstra(G,0)) # return list of distance from root which is 0