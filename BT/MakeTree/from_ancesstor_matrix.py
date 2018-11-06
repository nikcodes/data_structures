# Construct tree from ancestor matrix
# Given an ancestor matrix mat[n][n] where Ancestor matrix is defined as below.

#    mat[i][j] = 1 if i is ancestor of j
#    mat[i][j] = 0, otherwise 



class node:
    def __init__(self,val):
        self.val=val
    left,right = None,None


def inorder(root):
    if(root):
        inorder(root.left)
        print(root.val,end=' ')
        inorder(root.right)


n=int(input('Enter the number of nodes\n'))
a=[[int(i) for i in input().split()] for _ in range(n)]
parent=[0]*n
just=[(sum(a[i]),i)for i in range(n)]
just.sort()
nodelist=[None]*n

for s,i in just:
    if s:
        root=node(i)
        for j in range(n):
            if a[i][j] and parent[j]==0 :
                if(root.left):
                    root.right=nodelist[j]
                    parent[j]=1
                    break
                else:
                    root.left=nodelist[j]
                    parent[j]=1

        nodelist[i]=root

    else:
        nodelist[i]=node(i)

inorder(root)
