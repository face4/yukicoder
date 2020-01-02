import math, decimal
x, y, z = map(float, input().split())
a, b, c = decimal.Decimal(x), decimal.Decimal(y), decimal.Decimal(z)
zero = decimal.Decimal(0)

if a == zero:
    if b == zero:
        print(-1 if c==0 else 0)
    else:
        print(1)
        print(-c/b)
else:
    d = decimal.Decimal(b*b-4*a*c)
    if d < 0:
        print(0)
    elif d == 0:
        print(1)
        print(-b/a/decimal.Decimal(2))
    else:
        f = d ** decimal.Decimal(0.5)
        x,y = (-b-f)/a/decimal.Decimal(2), (-b+f)/a/decimal.Decimal(2)
        if x > y: x,y = y,x
        print(2)
        print(x)
        print(y)
