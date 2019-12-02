#coding on smartphone
a, b = map(int, input().split())
print(2**(max(0,sum([(b>>i^a>>i)&1 for i in range(32)])-1)) if a&b == a else 0)
