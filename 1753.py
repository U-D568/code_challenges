import sys
import heapq
import math
import time
from collections import deque

graph = dict()
heap = []

V, E = list(map(int, sys.stdin.readline().split()))
root = int(sys.stdin.readline())

for i in range(1, V + 1):
    graph[i] = dict()

for i in range(E):
    u, v, w = list(map(int, sys.stdin.readline().split()))
    if v in graph[u].keys():
        graph[u][v] = min(graph[u][v], w)
    else:
        graph[u][v] = w

visited = [False] * V
result = [math.inf] * V
result[root - 1] = 0

start_time = time.time()

heapq.heappush(heap, (0, root))
while heap:
    cost, node = heapq.heappop(heap)
    visited[node - 1] = True

    if cost != result[node - 1]:
        continue

    for next_node in graph[node].keys():
        if result[node - 1] + graph[node][next_node] < result[next_node - 1]:
            result[next_node - 1] = result[node - 1] + graph[node][next_node]
            heapq.heappush(heap, (result[next_node - 1], next_node))
print('dijkstra: ', time.time() - start_time)

for i in range(V):
    if visited[i]:
        print(result[i])
    else:
        print('INF')
