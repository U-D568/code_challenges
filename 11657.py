import sys

N, M = list(map(int, sys.stdin.readline().split()))
graph = {}
for _ in range(M):
    st, ed, w = list(map(int, sys.stdin.readline().split()))

    if st in graph.keys():
        graph[st].append((ed, w))
    else:
        graph[st] = [(ed, w)]


def dfs(root, goal, pre_weight):
    global is_cycle
    result = -1
    visited.append(root)
    if root in visited:
        is_cycle = True
        if pre_weight < 0:
            return -1
        else:
            return

    if root == goal:
        weights.append(pre_weight)
        return min(weights)

    for node, cur_weight in graph[root]:
        result = dfs(node, goal, pre_weight + cur_weight)
    return result


for i in range(N - 1):
    visited = []
    weights = []
    is_cycle = False
    print(dfs(1, i + 2, 0))
