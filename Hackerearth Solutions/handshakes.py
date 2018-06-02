from collections import *

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    d=defaultdict(lambda: [])
    child=defaultdict(lambda:0)
    nodelist = []

    for i in range(n):
        d[a[i]].append(i+1)
        child[a[i]]+=1
    hs=defaultdict(lambda:None)
    def add(node):
        global c
        if hs[node]:
            return hs[node]
        global c
        t=0
        for e in d[node]:
            t+=add(e)
        t+=child[node]
        hs[node]=t
        c+=t
        return t

    c = 0
    for k in d[0]:
        add(k)
    total = (n - 1) * n // 2
    print(c, total - c)
