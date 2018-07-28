#topological sort
from collections import defaultdict
d=defaultdict(lambda:[])
for _ in range(int(input())):
    u,v=[int(i) for i in input().split()]
    d[u].append(v)

visited={}
a=[] #This is our final ans in reverse order

def f(u):
    #if this node is already visited then no need to recur for this node
    if u in visited:
        return

    #first recur for its child nodes and once they all are visited and inserted in the stack mark this as visited as well and insert in the stack
    for e in d[u]:
        f(e)
    visited[u]=1
    a.append(u)

for e in list(d.keys()):
    f(e)
for e in a[::-1]:
    print(e,end=' ')


'''
8
1 3
2 3
2 4
3 5
4 6
5 8
5 6
6 7
'''
