#Recursive approach to delete a node in a BST

def smallest(root):
    while root.left:
        root=root.left
    return root

#This function will take a node which is root of a subtree and a value which we have to delete. It returns new updated node of the same subtree
def delete(root,val):
    if root==None:
        return root

    #Search for the value which is to deleted
    if val<root.val:
        root.left=delete(root.left,val)
        return root

    elif val>root.val:
        root.right=delete(root.right,val)
        return root

    #Else this is the node to be deleted

    #if the node has 1 or no child then simply copy the contents to the current node
    if root.left==None:
        root=root.right
        return root
    elif root.right==None:
        root=root.left
        return root

    #Both the child nodes of current node are present
    #find the smallest value in the right subtree and copy its value to the current node
    sm=smallest(root.right)
    root.val=sm.val

    #Delete the leaf node by updating its right subtree
    root.right=delete(root.right,root.val)

    return root

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

root=delete(root,15)
print(root.right.val)
