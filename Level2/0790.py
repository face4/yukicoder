def b(x):
    ret = 1
    while x > 1:
        ret *= x
        x -= 1
    return ret
n = int(input())
print(b(2*n)//b(n)//b(n+1))