#Inverting a binary tree

def f(r):
    #Base condition
    if not r:
        return

    #Swap the left and right child nodes
    r.left,r.right = r.right,r.left

    #recur for both the child nodes
    f(r.left)
    f(r.right)

print(root.right.left.val) #6
f(root)
print(root.right.right.val) #4

#input
#1 2 3 4 5 6 7
