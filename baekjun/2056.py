import sys
from collections import deque

N = int(sys.stdin.readline())

weights = {}
cost = {}
indegree = {}
graph = {}
queue = deque()

for i in range(N):
    graph[i + 1] = []

for i in range(N):
    data = list(map(int, sys.stdin.readline().split()))
    weights[i + 1] = data[0]
    indegree[i + 1] = data[1]

    if data[1] != 0:
        cost[i + 1] = -1
        for j in data[2:]:
            graph[j].append(i + 1)
    else:
        queue.append(i + 1)
        cost[i + 1] = data[0]

while queue:
    e = queue.popleft()

    for next_node in graph[e]:
        indegree[next_node] -= 1
        if indegree[next_node] == 0:
            queue.append(next_node)
        cost[next_node] = max(cost[next_node], cost[e] + weights[next_node])

print(max(cost.values()))
