from functools import reduce
print("Jiro" if reduce(lambda x,y:x^y, map(lambda x : x%4, map(int,input().split()))) == 0 else "Taro")