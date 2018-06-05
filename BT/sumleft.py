#A sample program to change a Binary Tree so that every node stores sum of all nodes in left subtree

#Defining the node class
class node:
    def __init__(self,val):
        self.val=val
    left,right=None,None


#Defining a recursive function that takes in a root and return the sum of all the nodes of the subtree rooted at that root
def f(root):

    #Base condition
    if not root:
        return 0

    #Finding the sum of left and right subtree through recursion
    leftsum = f(root.left)
    rightsum = f(root.right)

    #Changing the value of the current node by adding the sum of the left subtree
    root.val += leftsum

    #return the sum of this subtree which is now the updated root.val + sumright
    return root.val + rightsum


#Defining a inorder function to get the inorder traversal to compare the changes made to the tree
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val,end=' ')
        inorder(root.right)



'''
Driver code to test the above function

    Let us construct below tree
                1
               / \
              2   3
             / \   \
            4   5   6   


After running the above function the tree would be look like


      12
     / \
    6   3
   / \   \
  4   5   6

'''

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)
root.right.right = node(6)

print('Inorder traversal before updating the tree')
inorder(root)

f(root) #Function called
print('\n')

print('Inorder traversal after updating the tree')
inorder(root)
