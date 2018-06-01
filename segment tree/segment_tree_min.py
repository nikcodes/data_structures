import math
a=[int(i) for i in input().split()]
n=len(a)
max=max(a)
h=math.ceil(math.log(n,2))
b=[None]*(2*(2**h)-1)

def const(l,r,ind):
    if l==r:
        b[ind]=a[l]
        return
    m=(l+r)//2
    const(l,m,2*ind+1)
    const(m+1,r,2*ind+2)
    b[ind]=min(b[2*ind+1],b[2*ind+2])

def getmin(l,r,le,ri,ind):
    if l>r or r<0 or l>=n:
        return 'Invalid Input'
    global max
    if r<le or ri<l:
        return max
    if l<=le<=ri<=r:
        return b[ind]
    else:
        m=(le+ri)//2
        return min(getmin(l,r,le,m,2*ind+1),getmin(l,r,m+1,ri,2*ind+2))

def update(i,val,l,r,ind):
    if i<0 or i>=n:
        return "Can't update because of Invalid Input"
    if l==r==i:
        a[i]=val
        b[ind]=val
        return
    if l<=i<=r:
        m=(l+r)//2
        update(i, val, l, m, 2 * ind+1)
        update(i, val, m + 1, r, 2 * ind + 2)
        b[ind]=min(b[2*ind+1],b[2*ind+2])

#Driver code
const(0,n-1,0)
print(getmin(0,2,0,n-1,0))
update(0,3,0,n-1,0)
print(getmin(0,2,0,n-1,0))

