from collections import defaultdict

d=defaultdict(lambda:[])
v={}
pair=defaultdict(lambda:0)
for _ in range(int(input())):
    a,b=[int(i) for i in input().split()]
    d[a].append(b)
    d[b].append(a)
    v[a]=v[b]=0
    pair[(a,b)]=1
    pair[(b,a)]=1

def dfs(u):

    #Mark it as visited
    v[u]=1

    for e in d[u]:

        #If not visited then recur
        if v[e]==0 and dfs(e):
            return True

        #if e is visited and e is not the parent of u then it consist of cycle of atleast 3 nodes.
        #If it is the parent of u then it only consists fo two nodes and that is not a cycle
        elif v[e]==1 and pair[(e,u)]==0:
            return True


    return False

def cycle():
    for e in d.keys():
        #If not visited recur
        if v[e]==0 and dfs(e):
            return True
    return False

print(cycle())