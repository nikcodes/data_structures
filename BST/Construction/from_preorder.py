l=float('-infinity')
r=float('infinity')

class node:
    def __init__(self,val):
        self.val=val
    left,right = None,None

def f(l,r):
    global n,cur
    if cur>=n:
        return
    e=a[cur]
    root=None

    if l<=e<=r:
        root=node(e)
        cur+=1
        root.left=f(l,e-1)
        root.right=f(e+1,r)
    return root

a=[int(i) for i in input().split()]
n=len(a)
cur=0
root=f(l,r)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val,end=' ')
        inorder(root.right)

inorder(root)

10 7 3 9 8 15 12 18
