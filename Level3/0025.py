import math

n = int(input())
m = int(input())

g = math.gcd(n, m)

n //= g
m //= g

mm = m

while mm % 5 == 0:
    mm //= 5

while mm % 2 == 0:
    mm //= 2

if mm != 1:
    print("-1")
else:
    ans = 0
    while n != 0:
        ans = n//m
        n %= m
        n *= 10
    
    while ans % 10 == 0:
        ans /= 10
    
    ans %= 10

    print('%d' % ans)