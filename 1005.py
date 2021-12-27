import sys
from collections import deque

T = int(sys.stdin.readline())
for _ in range(T):
    N, K = list(map(int, sys.stdin.readline().split()))
    weight = []
    indegree = []
    outdegree = []
    cost = []

    weight = list(map(int, sys.stdin.readline().split()))
    for _ in range(N):
        indegree.append([])
        outdegree.append([])
        cost.append(0)

    for _ in range(K):
        st, ed = list(map(int, sys.stdin.readline().split()))
        indegree[ed - 1].append(st - 1)
        outdegree[st - 1].append(ed - 1)

    target = int(sys.stdin.readline()) - 1

    queue = deque()
    for i, node in enumerate(indegree):
        if len(node) == 0:
            cost[i] = weight[i]
            queue.append(i)
    
    while True:
        root = queue.popleft()
        if root == target:
            print(cost[target])
            break

        for e in outdegree[root]:
            indegree[e].remove(root)
            cost[e] = max(cost[e], weight[e] + cost[root])
            if len(indegree[e]) == 0:
                queue.append(e)