
na = int(input())
arr = [int(i) for i in input().split()]
q = int(input())


class node:
    def __init__(self, d):
        self.d = d
        self.r = None
        self.l = None


class tree:
    def __init__(self):
        self.root = None
        self.ref=None

    def add(self, data):
        n = node(data)
        if self.root:
            a = self.root
            if data > a.d:
                b = a.r
            elif data < a.d:
                b = a.l
            else:
                return 0

            while b:
                if data > b.d:
                    a, b = b, b.r
                elif data < b.d:
                    a, b = b, b.l
                else:
                    return 0
            if data > a.d:
                a.r = n
            elif data < a.d:
                a.l = n
            else:
                return 0

            if data == q:
                self.ref=a

        else:
            self.root=n


o=tree()
for e in arr:
    o.add(e)
if q > o.ref.d:
    final = o.ref.r
else:
    final = o.ref.l
def inorder(final):
    if final:
        print(final.d)
        inorder(final.l)
        inorder(final.r)
inorder(final)
