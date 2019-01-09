from collections import defaultdict

d=defaultdict(lambda:[])
n=int(input('Enter the number of edges\n'))
keys=[]
visited = {}
nodes=[]
for _ in range(n):
    u,v=[int(i) for i in input().split()]
    d[u].append(v)
    keys.append(u)
    nodes.extend([u,v])

    #Mark all nodes as unvisited
    visited[u]=visited[v]=0


def dfs(u):
    global visited
    visited[u]=1
    for e in d[u]:
        if visited[e]==0:
            dfs(e)

def mother():
    global visited
    for e in keys:
        if visited[e]==0:
            dfs(e)
            last=e
    visited={e:0 for e in nodes}
    dfs(last)
    if all(visited.values()):
        return last
    return None

print(f'Mother node is {mother()}')



