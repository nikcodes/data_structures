a=[int(i) for i in input().split()]
n=len(a)
b=[0]*(n+1)

def update(i,v): #i is 1-based index
    if i>n:
        print('invalid input')
        return
    while i<=n:
        b[i]+=v
        i+=(i&(-i))

def form(n):
    for i in range(1,n+1):
        update(i,a[i-1])

def getsum(i): #1-based index
    s=0
    while i>0:
        s+=b[i]
        # print(f'sum from {i} to {i-(i&(-i))+1} is {b[i]} ')
        i-=(i&(-i))
    return s

form(n)
while 1:
    #add to add or up to update
    s,i,val=input().split()
    val,i=int(val),int(i)
    if s=='up':
        update(i,val-a[i-1])
    else:
        update(i,val)
    print(getsum(3))

