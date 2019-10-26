n = int(input())
a = [int(x) for x in input().split()]
gt,lt = [0],[0]
for i in range(1, n):
    gt.append(1 if a[i-1] <= a[i] else 0)
    lt.append(1 if a[i-1] >= a[i] else 0)
    gt[i] += gt[i-1]
    lt[i] += lt[i-1]

q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    print(("1" if gt[r]-gt[l]==r-l else "0") + " " + ("1" if lt[r]-lt[l]==r-l else "0"))