""""
-----------------------------------------------------
Given a Binary Tree where each node has positive and negative values.
Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree.
The values of leaf nodes are changed to 0.
"""

#This function takes a root and returns the sum of the subtree rooted at that node
def f(root):
    if not root:
        return 0
    if not root.left and not root.right:
        t=root.val
        root.val=0
        return t
    sleft=f(root.left)
    sright=f(root.right)
    t=root.val
    root.val = sleft+sright
    return t+sleft+sright


class node:
    def __init__(self,val):
        self.val=val
    left,right=None,None

root = node(10)
root.left = node(-2)
root.right = node(6)
root.left.left = node(8)
root.left.right = node(-4)
root.right.left = node(7)
root.right.right = node(5)

f(root)

print(root.val)
print(root.left.val)
print(root.right.val)
