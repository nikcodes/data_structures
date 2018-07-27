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


while 1:
    #If cur is not None than append all the left nodes in the stack
    if cur:
        a.append(cur)
        cur=cur.left
        size+=1

    else:
        if size==0:
            break
        #If cur is none that means that in the last iteration we had appended a node whose left child was none so we just need to print this node
        top=a.pop()
        print(top.val,end=' ')
        size-=1

        #Recur for right subtree
        cur=top.right
