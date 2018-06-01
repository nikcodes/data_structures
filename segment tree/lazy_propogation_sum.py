import math
a=[int(i) for i in input().split()]
n=len(a)
max=max(a)
h=math.ceil(math.log(n,2))
size = 2*(2**h)-1
b=[None]*size

def cons(l,r,ind):
    if l==r:
        b[ind]=a[l]
        return
    m=(l+r)//2
    cons(l,m,2*ind+1)
    cons(m+1,r,2*ind+2)
    b[ind]=b[2*ind+1] + b[2*ind+2]

def getsum(l,r,le,ri,ind):
    global lazy
    if l>ri or le>r:
        return 0
    if l<=le and ri<=r:
        if lazy[ind]:
            return lazy[ind]*(ri-le+1)
        return b[ind]
    m=(le+ri)//2
    return getsum(l,r,le,m,2*ind+1) + getsum(l,r,m+1,ri,2*ind+2)

lazy=[None]*size

#For update operation updated element will be given for a given range
def updaterange(l,r,le,ri,ind,val):
    global lazy
    if lazy[ind] != None:
        b[ind] = lazy[ind]*(ri-le+1)
        if 2*ind+1<size and b[2*ind+1]:
            lazy[2*ind+1]=lazy[ind]
        if 2*ind+2<size and b[2*ind+2]:
            lazy[2*ind+2]=lazy[ind]
        lazy[ind]=None
    if l>ri or le>r:
        return
    if l<=le and ri<=r: #tree segment node range is completely in query range
        b[ind]=val*(ri-le+1)
        if ri!=le:
            lazy[2*ind+1]=val
            lazy[2*ind+2]=val
    else:
        m=(le+ri)//2
        updaterange(l,r,le,m,2*ind+1,val)
        updaterange(l, r, m+1,ri, 2*ind+2, val)
        b[ind]=b[2*ind+1] + b[2*ind+2]



#Driver code
cons(0,n-1,0)
print(getsum(2,4,0,n-1,0))
updaterange(2,4,0,n-1,0,7)
updaterange(4,4,0,n-1,0,4)
print(getsum(2,4,0,n-1,0))
# print(lazy)

