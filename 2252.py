#첫트
'''반례
5 7
4 3
4 2
4 1
5 4
3 2
3 1
2 1
'''
'''
import sys
from collections import deque


N, M = list(map(int, sys.stdin.readline().split()))

indegree = dict()
outdegree = dict()
order = dict()

for i in range(1, N + 1):
    indegree[i] = list()
    outdegree[i] = list()
    order[i] = i

for _ in range(M):
    a, b = list(map(int, sys.stdin.readline().split()))
    indegree[a].append(b)
    outdegree[b].append(a)

root = deque()
for i in indegree.keys():
    if len(indegree[i]) == 0:
        root.append(i)

while root:  # loop until root is empty
    print(root)
    node = root.popleft()
    for next_node in outdegree[node]:
        indegree[next_node].remove(node)
        if len(indegree[next_node]) == 0:
            root.append(next_node)

        if order[node] < order[next_node]:
            order[node], order[next_node] = order[next_node], order[node]  # swap

result = list(range(N))
for e in order.keys():
    result[order[e] - 1] = e

print(' '.join(map(str, result)))
'''

import sys
from collections import deque

N, M = list(map(int, sys.stdin.readline().split()))

indegree = dict()
outdegree = dict()
order = dict()

for i in range(1, N + 1):
    indegree[i] = list()
    outdegree[i] = list()
    order[i] = i

for _ in range(M):
    a, b = list(map(int, sys.stdin.readline().split()))
    indegree[b].append(a)
    outdegree[a].append(b)

root = deque()
for i in indegree.keys():
    if len(indegree[i]) == 0:
        root.append(i)

result = []
while root:  # loop until root is empty
    node = root.popleft()
    for next_node in outdegree[node]:
        indegree[next_node].remove(node)
        if len(indegree[next_node]) == 0:
            root.append(next_node)
    result.append(node)

print(' '.join(map(str, result)))