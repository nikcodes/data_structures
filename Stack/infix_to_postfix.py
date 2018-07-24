s=input()
a=[]
op=['+','-','*','/','//']
d={}
d['+']=d['-']=1
d['*']=d['/']=d['//']=2
for c in s:
    if c.isalnum():
        print(c,end='')
    elif c==')':
        while a and a[-1]!='(':
            print(a.pop(),end='')
        a.pop()
    elif c=='(':
        a.append('(')
    else:
        while a and a[-1]!='(' and d[a[-1]]>=d[c]:
            print(a.pop(),end='')
        a.append(c)
print(''.join(a[::-1]))
