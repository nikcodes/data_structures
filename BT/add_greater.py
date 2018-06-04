#Code to add all the greater elements to a node's value in a BST
def f(root):
    global s
    if root:
        f(root.right)
        s+=root.val
        root.val=s
        f(root.left)



class node:
    def __init__(self,val):
        self.val=val
    left,right=None,None


#Driver code to test the above code
root=node(10)
root.left=node(7)
root.right=node(15)
root.left.right=node(9)

s=0
f(root)
print(root.left.right.val)
