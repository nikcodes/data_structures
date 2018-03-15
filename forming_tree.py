n=int(input())
a=[int(i) for i in input().split()]
m=max(a)
d={}
for i in range(n):
    d[a[i]]=i+1
class node:
    def __init__(self,d,ind):
        self.d=d
        self.r=None
        self.l=None
        self.ind=ind

class tree:
    def __init__(self):
        self.root=node(a[0],1)
        self.arr=[]

def add(nodelist,arr,n):
    nextlevel=[]
    for e in nodelist:
        ind=e.ind
        if 2 * ind - 1 < n:
            e.l=node(a[2*ind-1],2*ind)
        if 2 * ind < n:
            e.r=node(a[2*ind],2*ind+1)
        if e.l:
            nextlevel.append(e.l)
        if e.r:
            nextlevel.append(e.r)
    if nextlevel[-1].d==arr[-1]:
        return 0
    nodelist=nextlevel
    return add(nodelist,arr,n)

o=tree()
add([o.root],a,n)
