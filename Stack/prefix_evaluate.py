#Just reverse the prefix to get postfix and then evaluate it
s=input()
a=[]
for c in s[::-1]:
    if c.isalnum():
        a.append(c)
    else:
        f=a.pop()
        l=a.pop()
        a.append(str(eval(f+c+l)))
print(a[0])
