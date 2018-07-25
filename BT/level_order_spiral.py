#Level order traversal in a spiral manner
nodelist=[root]
next=[1]
i=0

#Doing level order traversal in spiral manner
while next:
    next=[]
    for e in nodelist:
        if e.left:
            next.append(e.left)
        if e.right:
            next.append(e.right)
    if i==0:
        for e in nodelist:
            print(e.val,end=' ')
        i=1
    else:
        for e in nodelist[::-1]:
            print(e.val,end=' ')
        i=0
    nodelist=next
print()
