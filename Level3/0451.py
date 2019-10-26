n = int(input())
b = [int(input()) for i in range(n)]
low, high = 1, 10**18
sign = 1    # sign of k
acc = 0
for i in range(n):
    if i%2 == 0:
        acc *= -1
        sign *= -1
        acc += b[i]
    else:
        acc -= b[i]
    
    if sign == 1:
        low = max(low, 1-acc)
    else:
        high = min(high, acc-1)

if low > high:
    print(-1)
    exit()

print(n+1)
print(low)
for i in range(n):
    low = b[i]-low if i%2 == 0 else low-b[i]
    print(low)