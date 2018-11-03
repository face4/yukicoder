from decimal import Decimal

n = int(input())

print("{:.10f}".format(sum([Decimal(input()) for i in range(n)])))