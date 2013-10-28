d=["zero","one","two","three","four","five","six","seven","eight","nine"]
a=raw_input()
s=0
for i in range(len(a)):
    s+=int(a[i])
s=str(s)
for i in range(len(s)):
    print d[int(s[i])],
