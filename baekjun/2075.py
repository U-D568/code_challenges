import heapq
import sys

N = int(sys.stdin.readline())

heap = list(map(int, sys.stdin.readline().split()))
heapq.heapify(heap)
for i in range(1, N):
    row = list(map(int, sys.stdin.readline().split()))
    for num in row:
        if num > heap[0] and len(heap) == N:
            heapq.heappushpop(heap, num)
        elif num > heap[0]:
            heapq.heappush(heap, num)

print(heap[0])
