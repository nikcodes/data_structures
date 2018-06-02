from collections import *
n=int(input())
a=[int(i) for i in input().split()]
pre=defaultdict(lambda:0)
for e in a:
    pre[e]=1
d=defaultdict(lambda:[])
for i in range(n):
    d[a[i]].append(i)

class node:
    def __init__(self,d,ind):
        self.d=d
        self.r=None
        self.l=None
        self.ind=ind
class tree:
    pass

o=tree()
o.root=node(d[-1][0],d[d[-1][0]])
def add(nodelist):
    next=[]
    for e in nodelist:
        if pre[e.d]:
            index=e.ind
            if index!=[]:
                e.l=node(index[0],d[index[0]])
                next.append(e.l)
                index.pop(0)
            if index!=[]:
                e.r=node(index[0],d[index[0]])
                next.append(e.r)
    if next!=[]:
        nodelist=next
        add(nodelist)
    else:
        return 0
rootdata=d[-1]

# o.root.r=node(2,di[2])
# add([o.root.l,o.root.r])
add([o.root])
# print(o.root.d)
# print(o.root.l.d)
# print(o.root.r.d)
# print(o.root.r.l.l.d)
# print(o.root.l.l.d)
# print(o.root.l.r)
inorder=[]
def ino(root):
    if  root:
        global inorder
        ino(root.l)
        inorder.append(root.d)
        ino(root.r)
ino(o.root)
print(f'the inorder traversal is : {inorder}')
