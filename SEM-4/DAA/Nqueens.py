def backtrack(r, n):
    if r==n:
        res.append([" ".join(i) for i in B])
        return
    for c in range(n):
        if c in col or (r+c) in pd or (r-c) in nd:
            continue
        col.add(c)
        pd.add(r+c)
        nd.add(r-c)
        B[r][c] = 'Q'

        backtrack(r+1, n)

        col.remove(c)
        pd.remove(r+c)
        nd.remove(r-c)
        B[r][c] = '_'

n = int(input("Enter the number of queens: "))
col = set()
nd = set()
pd = set()
res = []
B = [['_']*n for i in range(n)]

backtrack(0, n)
print("Number of ways:",len(res))
print("Possible arrangements:")
for r in res:
    print(r)