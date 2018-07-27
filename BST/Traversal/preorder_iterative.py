while 1:
    if cur:
        print(cur.val,end=' ')
        a.append(cur)
        cur=cur.left
        size+=1

    else:
        if size==0:
            break
        cur=a.pop()
        size-=1
        cur=cur.right
