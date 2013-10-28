a=[]
n=int(raw_input());
openM=0
openI=0
closeM=0
closeI=0
for i in range(n):
    line=raw_input().split()
    a.append(line[0])
    tmp=line[1].split(":")
    o=int(tmp[0])*3600+int(tmp[1])*60+int(tmp[2])
    tmp=line[2].split(":")
    c=int(tmp[0])*3600+int(tmp[1])*60+int(tmp[2])

    if i==0:
        openM=o
        openI=i
        closeM=c
        closeI=i

    if o<openM:
        openM=o
        openI=i
    if c>closeM:
        closeM=c
        closeI=i


print a[openI], a[closeI]
