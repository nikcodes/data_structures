class node:
    def __init__(self,val):
        self.val=val
    left,right = None,None


def f(l,r):
    global n,cur
    if n<0:
        return
    root=None
    e=a[cur]
    if l<=e<=r:
        root=node(e)
        cur-=1
        root.right=f(e+1,r)
        root.left=f(l,e-1)
    return root


a=[int(i) for i in input().split()]
n=len(a)
l=float('-infinity')
r=float('infinity')
cur=n-1
root=f(l,r)


def inorder(root):
    if root:
        inorder(root.left)
        print(root.val,end=' ')
        inorder(root.right)

inorder(root)
