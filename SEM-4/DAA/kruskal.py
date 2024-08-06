def find(p, i): 
    if p[i] != i: 
        p[i] = find(p, p[i]) 
    return p[i]

def Kruskals(G, V):                       # main code
    mst = []
    G = sorted(G, key=lambda x:x[2])
    p = [i for i in range(V)]
    c, i, e = 0, 0, 0
    while e < V-1:
        u, v, wt = G[i]
        x, y = find(p, u), find(p, v)
        i+=1
        if x != y:
            mst.append([u, v, wt])
            p[y] = p[x]
            e += 1
            c += wt
    print("Mst tree: ", mst)
    print("Cost: ", c)



V = int(input("Vertices: "))
G = []
e = int(input("Edges: "))

print("Enter nodes:")
for i in range(e):
    u=int(input("Enter u: "))
    v=int(input("Enter v: "))
    wt=int(input("Enter wt: "))
    G.append([u,v,wt])

Kruskals(G, V)