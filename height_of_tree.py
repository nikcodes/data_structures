n = int(input())
a = [int(i) for i in input().split()]


class node:
    def __init__(self, d):
        self.d = d
        self.r = None
        self.l = None


class tree:
    def __init__(self):
        self.root = None

    def add(self,data):
        new = node(data)
        if self.root:
            f = self.root

            while 1:
                if data > f.d:
                    n = f.r
                elif data < f.d:
                    n = f.l
                else:
                    return 0
                if n:
                    f = n
                else:
                    if data > f.d:
                        f.r = new
                    elif data < f.d:
                        f.l = new
                    else:
                        return 0
        else:
            self.root = new




o = tree()
for e in a:
    o.add(e)
if len(set(a)) == 1:
    print(n)
else:
    from collections import *

    di = defaultdict(lambda: 0)

    roo=o.root
    def length(roo):

        if roo==None:
            return 0
        if di[roo.d]:
            return d[roo.d]
        v=max(length(roo.l),length(roo.r)) + 1
        di[roo.d]=v
        return v
    print(length(roo))


    def depth(root):
        if root == None:
            return 0
        if di[root.d]:
            return di[root.d]
        v=max(depth(root.l),depth(root.r)) + 1
        di[root.d]=v
        return v
