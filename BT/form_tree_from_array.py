'''

Constructing the array from the given array representation by doing a linear traversal and accessing the child nodes directlyE
The given list has been reversed and traversed from the back. Each time 2 elements are popped and they are considered as the
child nodes. The parent is popped from the parent array and the 2 nodes are assigned as the child nodes. The 2 child nodes are 
inserted back in the parent array. Parent array is considered as a stack

'''

a=[int(i) for i in input().split()]
a=a[::-1]
g=a.pop()

class node:
    def __init__(self,val):
        self.val=val
    left,right = None,None

root=node(g)
parent=[root]


#Forming the tree
while a:
    l,r = None,None
    l=node(a.pop())
    if a:
        r=node(a.pop())
    p=parent.pop(0)
    p.left=l
    p.right=r
    parent.append(p.left)
    parent.append(p.right)
