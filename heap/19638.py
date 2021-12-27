import sys
import heapq

N, H, T = list(map(int, sys.stdin.readline().split()))
T_ = T

giants = []
for _ in range(N):
    giant = int(sys.stdin.readline())
    if giant >= H:
        giants.append(giant)

giants = list(map(lambda x: -x, giants))
heapq.heapify(giants)

while giants and T > 0:
    giant = -heapq.heappop(giants)
    if giant > 1:
        giant = int(giant * 0.5)

    if giant >= H:
        heapq.heappush(giants, -giant)

    T -= 1

if T == 0 and giants:
    print('NO')
    print(-heapq.heappop(giants))
else:
    print('YES')
    print(T_ - T)
