s=input()
a=[]
for c in s:
    if c.isalnum():
        a.append(c)
    else:
        t=a[-2]+c+a[-1]
        a.pop()
        a.pop()
        a.append(str(eval(t)))
print(a[0])
