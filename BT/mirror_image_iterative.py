#Checking for mirror by iterative approach using a queue

class node:
    def __init__(self,val):
        self.val=val
    left,right = None,None

root=node(1)
root.left,root.right = node(2),node(2)
root.left.right=node(4)
root.right.left=node(4)

a=[root.left,root.right]

def f():
    while a:
        #Remove the first 2 nodes to check for symmetry
        f=a.pop(0)
        s=a.pop(0)

        #If both are none then continue
        if not f and not s:
            continue

        #If both are not none and values are equal
        if f and s and f.val==s.val:

            #Enqueue in the following order
            a.extend([f.left,s.right,f.right,s.left])

        else:
            #either only one of them is none or values are not equal
            return False

    #whole queue traversed so return True
    return True

print(f())
