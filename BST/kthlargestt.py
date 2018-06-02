class node:
    def __init__(self,d):
        self.d=d
    r,l=None,None

root=None
def add(d):
    global root
    n=node(d)
    if root==None:
        root=n
        return
    a=root
    if d>root.d:
        b=a.r
    elif d<root.d:
        b=a.l
    else:
        return
    while b:
        if d>b.d:
            a,b=b,b.r
        elif d<b.d:
            a,b=b,b.l
        else:
            return
    if d>a.d:
        a.r=n
    elif d<a.d:
        a.l=n
    else:
        return
        
def inorder(r):
    global c
    if r:
        inorder(r.r)
        if c==k-1:
            print(r.d)
            c=k
            return
        if c==k:
            return
        c+=1
        inorder(r.l)

l=[int(i) for i in input().split()]
c=0
for e in l:
    add(e)
k=int(input())
inorder(root)
