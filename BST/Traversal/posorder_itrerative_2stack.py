class node:
    def __init__(self,val):
        self.val=val
    left,right = None,None

root=node(10)
root.left=node(5)
root.right=node(15)
root.left.left=node(2)
root.left.right=node(7)
root.right.right=node(17)
root.right.left=node(13)

a=[root]
b=[]
size=0
cur=root

#using 2 stack
while a:
    t=a.pop()
    b.append(t)
    if t.left:
        a.append(t.left)
    if t.right:
        a.append(t.right)

for e in b[::-1]:
    print(e.val,end=' ')
