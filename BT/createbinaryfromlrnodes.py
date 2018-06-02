from collections import *
class node:
    def __init__(self, d,ind):
        self.d = d
        self.ind = ind
    l, r = None, None

for _ in range(int(input())):
    n = int(input())
    d = defaultdict(lambda: 0)
    ind = defaultdict(lambda: 0)
    i = 1
    for _ in range(n):
        a = [int(i) for i in input().split()]
        if ind[a[0]] == 0:
            ind[a[0]] = i
            ind[a[1]] = 2 * i
            ind[a[2]] = 2 * i + 1
            d[i] = a[0]
            d[2 * i] = a[1]
            d[2 * i + 1] = a[2]
            i += 1
        else:
            t = ind[a[0]]
            ind[a[1]] = 2 * t
            ind[a[2]] = 2 * t + 1
            d[t] = a[0]
            d[2 * t] = a[1]
            d[2 * t + 1] = a[2]

    root = node(d[1], 1)


    def add(nodelist):
        next = []
        for e in nodelist:
            i = e.ind
            if d[2 * i]:
                e.l = node(d[2 * i], 2 * i)
                next.append(e.l)
            if d[2 * i + 1]:
                e.r = node(d[2 * i + 1], 2 * i + 1)
                next.append(e.r)
        if next == []:
            return
        add(next)
    add([root])

    def post(root):
        if root:
            print(root.d,end=' ')
            post(root.l)
            post(root.r)
    post(root)
    print()
