class node:
    def __init__(self,d):
        self.d=d
        self.l=None
        self.r=None

class tree:
    def __init__(self):
        self.root=None
        self.size=0
        self.leaves=[]

    def add(self,data):
        n=node(data)
        if self.root:
            a=self.root
            if data>a.d:
                b=a.r
            elif data<a.d:
                b=a.l
            else:
                return None
            while b:
                # print(f'a and b are {a.d}:{b.d}')
                if data > b.d:
                    a,b=b,b.r
                elif data<b.d:
                    a,b=b,b.l
                else:
                    return 0
            # print(f'a  is {a.d} and length is {self.size}')

            if data>a.d:
                a.r=n
            elif data<a.d:
                a.l=n
            else:
                return 0
            self.size += 1
            try:
                self.leaves.remove(a.d)
            except ValueError:
                pass
            self.leaves.append(data)


        else:
            self.root=n
            self.leaves.append(data)
            self.size+=1
            # print(self.leaves)

    def find(self,data):
        n=node(data)
        f=self.root
        cs=0
        while f:
            if f.d==data:
                print('present')
                cs=1
                break
            elif data>f.d:
                f=f.r
            else:
                f=f.l
        if cs==0:
            print('not present')
    def s(self):
        print(f'length is {self.size}')



o=tree()
print('Enter the elements which you want to insert in the tree')
li=[int(i) for i in input().split()]
for e in li:
    o.add(e)
o.s()
print(f'the leaf nodes are: { o.leaves}')
print('Enter the elements which you want to check')
find=[int(i) for i in input().split()]
for e in find:
    o.find(e)
