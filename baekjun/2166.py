import sys
import math

N = int(sys.stdin.readline())

x = []
y = []
for _ in range(N):
    a, b = list(map(int, sys.stdin.readline().split()))
    x.append(a)
    y.append(b)
x.append(x[0])
y.append(y[0])
area = 0
x1, y1 = x[0], y[0]
for x2, y2 in zip(x, y):
    width = (x1 + x2) * 0.5
    height = y2 - y1
    area += width * height
    x1, y1 = x2, y2

print(round(abs(area), 2))