#print the number of paths from root node that give desired sum
#This program explores all the paths considering negative numbers as well

s=0

def f(nodelist):
    global s
    next=[]
    for e in nodelist:
        if e.val==e.s:
            s+=1
        
        if e.left:
            e.left.s=e.s-e.val
            next.append(e.left)

        if e.right:
            e.right.s=e.s-e.val
            next.append(e.right)
    if not next:
        return
    nodelist=next
    f(nodelist)



class node:
    def __init__(self,val):
        self.val=val

    left,right,s=None,None,0


#Driver code
root=node(2)
root.left=node(1)
root.right=node(2)
root.left.left=node(1)
root.left.right=node(2)
root.right.left=node(1)
root.right.right=node(0)

root.s=5
f([root])
print(s)
