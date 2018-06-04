#Maximum number of distinct nodes on a path from root node to leaf node
d = {}
def f(root,s):
    if not root:
        return s

    try:
        d[root.val]+=1
    except KeyError:
        d[root.val]=1
        s+=1

    ans= max(f(root.left,s),f(root.right,s))
    d[root.val]-=1
    if d[root.val]==0:
        s-=1
    return ans

class node:
    def __init__(self,val):
        self.val=val
    left,right=None,None
    
    
#Construct a tree
root=node(34)

#Call the function
f(root,0)
