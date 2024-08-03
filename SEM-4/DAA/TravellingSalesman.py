V = 4
ans = []
def tsp(G, v, pos, n, cnt, cost):
    if (cnt == n and G[pos][0]):
        ans.append(cost + G[pos][0])
        return
    for i in range(n):
        if (v[i] == False and G[pos][i]):
            v[i] = True
            tsp(G, v, i, n, cnt + 1, cost + G[pos][i])
            v[i] = False


n = 4
G= [[ 0, 10, 15, 20 ],
        [ 10, 0, 35, 25 ],
        [ 15, 35, 0, 30 ],
        [ 20, 25, 30, 0 ]]
v = [False for _ in range(n)]
v[0] = True
tsp(G, v, 0, n, 1, 0)
print("min cost:",min(ans))