import math
n,q=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
height=math.ceil(math.log(n,2))
size = 2*(2**height) - 1
b=[None]*size

def cons(l,r,ind):
    if l==r:
        b[ind]=a[l]
        return a[l]
    m=(l+r)//2
    b[ind]=cons(l,m,2*ind+1) + cons(m+1,r,2*ind+2)
    return b[ind]

def getsum(l,r,le,ri,ind):
    if ri<l or r<le:
        return 0
    if l<=le<=ri<=r:
        return b[ind]
    m=(le+ri)//2
    return getsum(l,r,le,m,2*ind+1) + getsum(l,r,m+1,ri,2*ind+2)

def update(i,l,r,val,ind):
    if l==r and l==i:
        a[l]=val
        b[ind]=val
        return
    if l<=i<=r:
        m=(l+r)//2
        update(i,l,m,val,2*ind+1)
        update(i,m+1,r,val,2*ind+2)
        b[ind] = b[2*ind+1] + b[2*ind+2]

cons(0,n-1,0)
# print(b)
print(getsum(2,6,0,n-1,0))
update(3,0,n-1,5,0)
update(3,0,n-1,1,0)
update(3,0,n-1,5,0)
print(getsum(2,6,0,n-1,0))


# print(getsum(0,3,0,4,0))

# 13 1
# 4 6 8 2 1 5 8 4 3 4 6 10 1


# print(getmin(4,4))
# update(4,1)
# for e in b:
#     if not e or e.l==e.r:
#         continue
#     print(f'min of range {e.l} to {e.r} is {e.m} and index in tree is {e.i}')


