n = int(input())
li = list(map(int, input().split()))
xb = n*(n-1)/2/n
yb = sum(li)/n
s = t = 0
for i in range(n):
    s += (i-xb)*(li[i]-yb)
    t += (i-xb)*(i-xb)
d = s/t
b = yb-d*xb
e = 0
for i in range(n):
    e += (b+i*d-li[i])*(b+i*d-li[i])
print(b, d)
print(e)