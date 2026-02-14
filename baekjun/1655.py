import sys
import heapq

N = int(sys.stdin.readline())

maxheap = []
minheap = []

num = int(sys.stdin.readline())
heapq.heappush(maxheap, -num)
print(-maxheap[0])
for _ in range(1, N):
    num = int(sys.stdin.readline())

    if num < -maxheap[0]:
        heapq.heappush(maxheap, -num)
    else:
        heapq.heappush(minheap, num)
    
    if len(maxheap) - len(minheap) > 1:
        tmp = -heapq.heappop(maxheap)
        heapq.heappush(minheap, tmp)
    elif len(maxheap) - len(minheap) < -1:
        tmp = heapq.heappop(minheap)
        heapq.heappush(maxheap, -tmp)

    if len(maxheap) - len(minheap) >= 0:
        print(-maxheap[0])
    else:
        print(minheap[0])
