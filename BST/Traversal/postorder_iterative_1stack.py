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

a=[]
size=0
cur=root

lastprinted=None
while 1:
    if cur:
        a.append(cur)
        cur=cur.left
        size+=1

    else:
        if size==0:
            break
        t=a[-1]
        
        #if right node does not exist or right subtree is already printed of the node at the top of the stack then print this element and pop it
        if t.right==None or t.right.val==lastprinted:
            print(t.val,end=' ')
            lastprinted=t.val
            a.pop()
            size-=1

        else:
            cur=t.right
