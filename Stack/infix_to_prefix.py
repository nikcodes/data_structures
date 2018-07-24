#Reverse the given string and then find its postfix and then reverse the postfix to get prefix
s=input()
new=''
for c in s[::-1]:
    if c=='(':
        new+=')'
    elif c==')':
        new+='('
    else:
        new+=c
s=new
a=[]
op=['+','-','*','/','//']
d={}
d['+']=d['-']=1
d['*']=d['/']=d['//']=2
ans=[]
for c in s:
    if c.isalnum():
        ans.append(c)
    elif c==')':
        while a and a[-1]!='(':
            ans.append(a.pop())
        a.pop()
    elif c=='(':
        a.append('(')
    else:
        while a and a[-1]!='(' and d[a[-1]]>=d[c]:
            ans.append(a.pop())
        a.append(c)
ans.extend(a[::-1])
print(''.join(ans[::-1]))
