def find(p, i): 
    if p[i] != i: 
        p[i] = find(p, p[i])            # p = parent
    return p[i]

def Kruskals(G, V):                       # main code
    mst = []
    G = sorted(G, key=lambda x:x[2])
    p = [i for i in range(V)]
    c, i, e = 0, 0, 0
    while e < V-1:
        u, v, wt = G[i]                     # wt = weight
        x, y = find(p, u), find(p, v)       # e= edges
        i+=1                                # V = vertices
        if x != y:                          # u,v are starting and ending node of an edge.
            mst.append([u, v, wt])          #c = count
            p[y] = p[x]
            e += 1
            c += wt
    print("Mst tree: ", mst)
    print("Cost: ", c)



V = int(input("Vertices: "))
G = []                                      # G is graph
e = int(input("Edges: "))

print("Enter nodes:")
for i in range(e):
    u=int(input("Enter u: "))
    v=int(input("Enter v: "))
    wt=int(input("Enter wt: "))
    G.append([u,v,wt])

Kruskals(G, V)