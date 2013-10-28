n=int(raw_input())
a=raw_input().split()
ina2=0
sum=0
# Get the non-zeros maximum sequence
ina=0
inb=0
max=int(a[0])
for i in range(n):
    if sum<0:
        sum=0
        ina2=i
    sum+=int(a[i])
    if max<sum:
        max=sum
        ina=ina2
        inb=i

if max<0:
    max=0
    ina=0
    inb=n-1

print max,a[ina],a[inb]







if 0:
    n=int(input())
    a=[0 for i in range(n)]
    b=input().split()
    mi=0
    mj=0
    m=-1
    tmp=0
    for i in range(n):
        a[i]=int(b[i])
        if m<a[i]:
            m=a[i]
            mi=i
            mj=i
    
    for i in range(0,n-1):
        tmp=a[i]
        for j in range(i+1,n):
            tmp=tmp+a[j]
            if m<tmp:
                m=tmp
                mi=i
                mj=j
    if m<0:
        mi=0
        mj=n-1
        m=0
    print(m,a[mi],a[mj])
