import sys
from collections import deque

N, M = list(map(int, sys.stdin.readline().split()))
graph = {}
indegree = {}
root = []

for i in range(N):
    graph[i + 1] = []
    indegree[i + 1] = 0

for _ in range(M):
    st, ed = list(map(int, sys.stdin.readline().split()))
    graph[st].append(ed)
    indegree[ed] += 1

for key in indegree.keys():
    if indegree[key] == 0:
        root.append(key)

result = []
while root:
    root.sort(reverse=True)
    node = root.pop()
    result.append(node)
    for next in graph[node]:
        indegree[next] -= 1
        if indegree[next] == 0:
            root.append(next)

print(' '.join(map(str, result)))
