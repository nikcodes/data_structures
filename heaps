n=int(input())
t=n
a=[int(i) for i in input().split()]
b=a.copy()

def swap(i,n):
    smallest=i
    m=a[i]
    if 2*i+1<n and a[2*i+1]<m:
        m=a[2*i+1]
        smallest=2*i+1
    if 2*i+2<n and a[2*i+2]<m:
        smallest=2*i+2
    if i==smallest:
        return 0
    a[i],a[smallest]=a[smallest],a[i]
    return swap(smallest,n)

sorted=[]
def sorting(n):
    for i in range(n//2-1,-1,-1):
        swap(i,n)
    sorted.append(a.pop(0))
    if n-1==0:
        return
    return sorting(n-1)
# sorting(n)
# print(f'sorted is {sorted}')



def heap(n):
    for i in range(n//2-1,-1,-1):
        swap(i,n)

def delete(ind): #1-based index
    a[ind-1]=a[-1]
    a.pop()
    global n
    n-=1
    swap(ind-1,n)
    return a
