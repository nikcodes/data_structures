#Sorting a stack with the help of other stack
for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    b=[a.pop()]
    l=0

    while l<n:
        while a and b[-1]<=a[-1]:
            b.append(a.pop())
            l+=1
        if not a:
            break
        j=a.pop()
        while b and b[-1]>j:
            a.append(b.pop())
            l-=1
        b.append(j)
        l+=1

print(b)
