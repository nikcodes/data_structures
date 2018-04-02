#constructing the binary tree
n, r = [int(i) for i in input().split()]
class node:
    def __init__(self, d):
        self.d = d

    l, r = None, None

root = node(r)
a=[]
for _ in range(n-1):
    t=[]
    t.append(input())
    t.append(int(input()))
    t.append(len(t[0]))
    a.append(t)
a.sort(key=lambda a:a[2])
for e in a:
    p = e[0]
    d = e[1]
    fir = root
    for c in p[:-1]:
        if c == 'L':
            fir = fir.l
        else:
            fir = fir.r
    if p[-1] == 'L':
        fir.l = node(d)
    else:
        fir.r = node(d)

#finding the height of each node in the tree
def height(n):
    # global dia
    global m
    if n==None:
        return 0
    h1=height(n.l)
    h2=height(n.r)
    # dia.append(h1+h2+1)
    m=max(m,h1+h2+1)
    h= max(h1,h2)+1
    return h
# dia=[]
m=0
height(root)
# print(dia)
print(m)
