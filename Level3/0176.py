a, b, t = map(int, input().split())
ans = (t//b + 1)*b
for i in range(min(t//b+1, a+1)):
    ans = min(ans, b*i + (t-b*i+a-1)//a * a)
print(ans)