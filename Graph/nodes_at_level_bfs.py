#Count the number of nodes at given level in a tree using BFS.

from collections import defaultdict
d=defaultdict(lambda:[])
level=defaultdict(lambda:None)
level[0]=0
count=0

n=int(input())
for _ in range(n):
    u,v=[int(i) for i in input().split()]
    d[u].append(v)
    d[v].append(u)
givenlevel=int(input())

#bfs travesal of the tree
nodes=[0]

for e in nodes:
    if level[e]==givenlevel:
        count+=1

    for u in d[e]:
        if level[u]==None:
            nodes.append(u)
            level[u]=level[e]+1

print(count)