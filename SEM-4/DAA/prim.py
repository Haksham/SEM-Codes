INF = 999

def Prims(G, visited, n): 
    v, s = 0, 0
    visited[0] = 1
    while (v < n-1):
        m, x, y = INF, 0, 0
        for i in range(n):
            if visited[i]:
                for j in range(n):
                    if not visited[j] and G[i][j] and m > G[i][j]:
                      m, x, y = G[i][j], i, j
        print(x,y,":",G[x][y])
        visited[y] = 1
        s += G[x][y]
        v += 1
    print("Cost: ", s)


visited = [0]*5

arr = [
    [0, 2, 0, 6, 2],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

Prims(arr, visited,5)