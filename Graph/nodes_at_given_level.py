#number of nodes at given level using dfs

n=int(input())
d=defaultdict(lambda:[])
level=defaultdict(lambda:None)
level[0]=0
for _ in range(n):
    u,v=[int(i) for i in input().split()]
    d[u].append(v)
    d[v].append(u)
givenlevel=int(input())
count=0

#the argument of the function as its level precalculated
def dfs(u):
    global count
    if level[u]==givenlevel:
        count+=1

    #recur for child nodes only if its not visited
    for e in d[u]:
        if level[e]==None:
            level[e]=level[u]+1
            dfs(e)

dfs(0)
print(count)
