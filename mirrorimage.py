from collections import *
n,q=[int(i) for i in input().split()]
d=defaultdict(lambda:[])
parent=defaultdict(lambda:[])
a=[]
for _ in range(n-1):
    t=[i for i in input().split()]
    d[int(t[0])].append([int(t[1]),t[2]])
    parent[int(t[1])]=[int(t[0]),t[2]]
class node:
    def __init__(self,d):
        self.d=d
    l=None
    r=None

root=node(1)
def add(nodelist):
    next=[]
    for e in nodelist:
        if d[e.d]!=[]:
            first=d[e.d].pop(0)
            if first[1]=='L':
                e.l=node(first[0])
            else:
                e.r=node(first[0])
        if d[e.d]!=[]:
            sec=d[e.d].pop(0)
            if sec[1]=='L':
                e.l=node(sec[0])
            else:
                e.r=node(sec[0])
        if e.l:
            next.append(e.l)
        if e.r:
            next.append(e.r)
    if next==[]:
        return 0
    return add(next)
add([root])
print()
for _ in range(q):
    n=int(input())
    path=[]
    while n!=1 and n!=None:
        path.append(parent[n][1])
        n=parent[n][0]
        # print(f'n is {n}')
    # print(f'path for {n} is {path}')
    if n!=1:
        print(-1)
    else:
        path.reverse()
        first=root
        for e in path:
            if e=='R':
                first=first.l
            else:
                first=first.r
            if first==None:
                break
        if first!=None:
            print(first.d)
        else:
            print(-1)
