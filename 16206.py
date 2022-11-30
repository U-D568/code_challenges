import sys
import heapq

N, M = list(map(int, input().split()))

cnt = 0
cakes = []
for cake in list(map(int, input().split())):
    if cake == 10:
        cnt += 1
    elif cake == 20:
        cakes.append((-1, cake))
    elif cake > 10:
        cakes.append((cake % 10, cake))

heapq.heapify(cakes)
while cakes and M > 0:
    _, cake = heapq.heappop(cakes)
    M -= 1
    remain = cake - 10
    cnt += 1

    if remain == 20:
        heapq.heappush(cakes, (-1, remain))
    elif remain == 10:
        cnt += 1
    elif remain > 10:
        heapq.heappush(cakes, (remain % 10, remain))

print(cnt)
