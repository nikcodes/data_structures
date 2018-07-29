#this func will return the updated root of root taken as argument
def f(root,l,r):
    if root==None:
        return
    if l<=root.val<=r:
        root.left=f(root.left,l,r)
        root.right = f(root.right, l, r)
        return root
    elif root.val<l:
        return f(root.right,l,r)
    return f(root.left,l,r)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val,end=' ')
        inorder(root.right)


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

inorder(root)
print()
root=f(root,3,13)
inorder(root)
