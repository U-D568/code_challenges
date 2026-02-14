import sys
from collections import deque

N, M = list(map(int, sys.stdin.readline().split()))
graph = dict()
visited = [False] * (N + 1)
queue = deque()

for i in range(1, N + 1):
    graph[i] = []

for _ in range(M):
    row = list(map(int, sys.stdin.readline().split()))
    previous_node = row[0]
    for i in row[1:]:
        graph[previous_node].append(i)
        previous_node = i
print(graph)
