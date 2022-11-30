import math
import heapq

N, M = map(int, input().split())

if N > M:
    N = N % M

chop = 0
storage = [-M] * N
remains = 0
while storage:
    piece = -heapq.heappop(storage)
    if piece > N:
        heapq.heappush(storage, -(piece - N))
        chop += 1
    else:
        remains += piece

    if remains > N:
        heapq.heappush(storage, -(remains - N))
        remains = 0
        chop += 1
    remains = remains % N
print(chop)
