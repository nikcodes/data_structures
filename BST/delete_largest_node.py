#delete a node from a bst whose value is nearest and less than the given value

#This function returns the node value which we have to delete
def f(root,val):
    #Base condition
    if root==None:
        return None

    #If current node value is greater than val then recur for left subtree
    if root.val>val:
        return f(root.left,val)

    if root.val==val:
        return val

    #Keep visiting the right nodes till it is possible
    while root.right and root.right.val<val:
        root=root.right

    #The loop terminates either because the root.right.val>val  or it was a None

    #If it is leaf value and its value is still less than or equal to the required value then this is the value we have to return
    if root.right==None and root.val<=val:
        return root.val

    #Else if the right subtree of current node exists and the current node value is greater than val then the required value might be in left subtree
    #of right child so recur for that node and compare with the current node value and return the larger one
    if root.right and root.right.val>val:
        t=f(root.right.left,val)
        if t!=None:
            return max(root.val,t)
        return root.val




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

print(f(root,int(input())))
