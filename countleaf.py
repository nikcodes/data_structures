n=int(input())
a=[int(i) for i in input().split()]
k=int(input())
from collections import defaultdict
d=defaultdict(lambda:[])
for i in range(n):
    d[a[i]].append(i)
root=d[-1][0]
curr=[root]
c=0
while 1:
    next=[]
    for e in curr:
        if d[e]!=[] and e!=k:
            next.extend(d[e])
        elif d[e]==[] and e!=k:
            c+=1
    if next==[]:
        break
    curr=next
print(c)
