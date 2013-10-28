a=raw_input().split()
f=0
c=0
for i in range(int(a[0])):
    n=int(a[i+1])
    if n>f:
        c+=6*(n-f)
    if n<f:
        c+=4*(f-n)
    if i==0 or f!=n:
        c+=5
    f=n
print(c)
