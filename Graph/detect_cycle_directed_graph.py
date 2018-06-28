from collections import defaultdict
d=defaultdict(lambda:[])
v={}
stack={}
for _ in range(int(input())):
    a,b=[int(i) for i in input().split()]
    d[a].append(b)
    v[a]=v[b]=0
    stack[a]=stack[b]=0

def dfs(u):
    #Mark the current node as visited and add it to the stack
    v[u]=1
    stack[u]=1

    for e in d[u]:
        #If this node is visited and present in current stack then cycle is present
        if v[e] and stack[e]:
            return True

        #If it is not visited then call the same function for e
        if v[e]==0 and dfs(e):
            return True

    #Remove the current element from the stack
    stack[u]=0
    return False


def cycle():
    keys=list(d.keys())
    for e in keys:
        if v[e]==0 and dfs(e):
            return True
    return False
print(cycle())