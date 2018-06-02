class node:
    def __init__(self,d):
        self.d=d
        self.next=None
        self.previous=None

class ll:
    def __init__(self):
        self.head=None
        self.tail=None
        self.size=0
    def add(self,d):
        newn=node(d)
        if self.head:
            if self.size >= 2:
                self.tail.next=newn
                newn.previous=self.tail
                self.tail=newn
            else:
                self.head.next=newn
                newn.previous=self.head
                self.tail=newn
        else:
            self.head=newn
        self.size+=1

    def display(self,ind):
        first=self.head
        count=ind-1
        while count:
            first=first.next
            count-=1
        print(first.d)

    def fl(self):
        print(self.head.d)
        print(self.tail.d)
    def s(self):
        print(self.size)
    def __repr__(self):
        return f'first data object is {self.head.d} and last one is {self.tail.d}'
    def reverse(self):
        last=self.tail
        while 1:
            print(last.d,end=' ')
            if last.previous:
                last=last.previous
            else:
                break
    def insert(self,ind,data):#insert the data at ind index(1-based) and move the next elemnts forward
        c=1
        nn=node(data)
        first=self.head
        while 1:
            if c!=ind:
                first=first.next
                c+=1
            else:
                leftnode=first.previous
                nn.next=first
                first.previous.next=nn
                first.previous=nn
                nn.previous=leftnode
                break


    def pr(self):#printing all the elements
        first=self.head
        while 1:
            if first:
                print(first.d,end=' ')
                first=first.next
            else:
                print()
                break

    def delete(self,ind):
        first=self.head
        for i in range(ind-1):
            first=first.next
        first.previous.next=first.next
        first.next.previous=first.previous

#driver program to check the code
o=ll()
o.add(3)
o.add(3)
o.add(7)
o.add(56)
o.add(65)
o.add(54)
o.add(67)
o.add(43)
o.insert(3,100)
o.insert(3,1000)
o.insert(10,70)
o.delete(4)
# o.traverse(3,100)
o.pr()
first=o.head
print(first.d,first.next.d,first.next.next.d)
