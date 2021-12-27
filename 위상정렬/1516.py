import sys
from collections import deque

N = int(sys.stdin.readline())

graph = dict()
result = [0] * (N + 1)
queue = deque()

for i in range(1, N + 1):
    graph[i] = [0, [], 0]

for i in range(1, N + 1):
    row = list(map(int, sys.stdin.readline().split()))
    graph[i][0] = row[0]
    for j in row[1:]:
        if j == -1:
            break
        graph[i][2] += 1
        graph[j][1].append(i)
    if graph[i][2] == 0:
        queue.append(i)

while queue:
    i = queue.popleft()
    result[i] += graph[i][0]

    for j in graph[i][1]:
        result[j] = max(result[j], result[i])
        graph[j][2] -= 1
        if graph[j][2] == 0:
            queue.append(j)

for i in result[1:]:
    print(i)
