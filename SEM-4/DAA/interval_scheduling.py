list=[[90,91],[94,120],[80,90],[110,113],[150,190],[180,200]]
list=sorted(list,key=lambda x:x[1])
t=[]
c=0
p=0
for i in list:
  if p<i[0]:
    t.append(i)
    p=i[1]
    c+=1
print(t)
print("total: ",c)
