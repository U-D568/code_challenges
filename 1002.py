import math
#두 원과 접점 관계
T = int(input())

for i in range(T):
    x1, y1, r1, x2, y2, r2 = list(map(int, input().split()))
    dist = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    
    if dist == 0 and r1 == r2:
        print(-1)
    elif dist == r1 + r2 or dist == abs(r1 - r2):
        print(1)
    elif dist > r1 + r2 or dist < abs(r1 - r2):
        print(0)
    elif dist < r1 + r2 and dist > abs(r1 - r2):
        print(2)