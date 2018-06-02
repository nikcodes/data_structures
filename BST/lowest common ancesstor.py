n = int(input())
a = [int(i) for i in input().split()]
b, c = [int(i) for i in input().split()]
d1 = min(b, c)
d2 = max(b, c)


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
                    next = f.r
                else:
                    next = f.l
                if next == None:
                    if data > f.d:
                        f.r = new
                    else:
                        f.l = new
                    break
                else:
                    f = next
        else:
            self.root=new


o = tree()
for e in a:
    o.add(e)
# print(o.root.d,o.root.r.l.d)
first = o.root
while 1:
    if first.d < d1:
        first = first.r
    elif first.d > d2:
        first = first.l
    else:
        break
print(f'lca is {first.d}')
while 1:
    if first.d < d2:
        first = first.r
    else:
        print(first.d)
        break

