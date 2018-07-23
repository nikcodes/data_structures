#Min heap to sort

a=[int(i) for i in input().split()]
n=len(a)


def swap(i,n):
    m=i
    mini=a[i]
    if 2*i+1<n and a[2*i+1]<mini:
        m=2*i+1
        mini=a[2*i+1]

    if 2*i+2<n and a[2*i+2]<mini:
        m=2*i+2

    if i==m:
        return
    a[i],a[m] = a[m],a[i]
    swap(m,n)

def makeheap(n):
    for i in range(n//2-1,-1,-1):
        swap(i,n)


def sorting(n):
    makeheap(n)
    a[0],a[n-1] = a[n-1],a[0]
    for size in range(n-1,1,-1):
        swap(0,size)
        a[0],a[size-1] = a[size-1],a[0]

sorting(n)
print(a)
