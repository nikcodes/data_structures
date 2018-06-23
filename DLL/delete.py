class node:
    def __init__(self,val):
        self.val=val
    next,prev = None,None

head,tail = None,None
size=0

def add(val):
    global head,size,tail
    size+=1
    if not head:
        head=node(val)
        tail=head
        return
    n=node(val)
    tail.next=n
    n.prev=tail
    tail=n


#function for printing
def dis():
    global head
    while head:
        print(head.val,end=' ')
        head=head.next
    print()

def rev():
    global tail
    t=tail
    while t:
        print(t.val,end=' ')
        t=t.prev
    print()

def delete(k):
    global head,tail,size
    if k==size:
        tail=tail.prev
        tail.next=None
        size-=1
        return

    if k==1:
        head=head.next
        head.prev=None
        size-=1
        return

    h=head
    while k-1:
        h=h.next
        k-=1
    h.prev.next=h.next
    h.next.prev=h.prev
    size-=1


n=int(input())
a=[int(i) for i in input().split()]
k=int(input())

for e in a:
    add(e)

delete(5)
dis()
