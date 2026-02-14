import sys


def get_adjacent(node):
    if node == 0 or node == N:
        a = node - 1 + N
    else:
        a = node - 1

    if node == N - 1 or node == N * 2 - 1:
        b = node - N + 1
    else:
        b = node + 1

    if node < N:
        c = node + N
    else:
        c = node - N

    return a, b, c


T = int(input())
for _ in range(T):
    N, W = list(map(int, input().split()))

    enemy = list(map(int, sys.stdin.readline().split()))
    enemy += list(map(int, sys.stdin.readline().split()))

    selected = []
    result = []

    graph = dict()
    for node in list(range(len(enemy))):
        graph[node] = []
        adjacent_nodes = get_adjacent(node)

        for look_ahead in adjacent_nodes:
            if enemy[look_ahead] + enemy[node] <= W:
                graph[node].append(look_ahead)
        if len(graph[node]) == 0:
            selected.append(node)
            result.append(node)

    while len(selected) != 2 * N:
        min = 4
        for key in graph.keys():
            if key in selected:
                continue
            if min > len(graph[key]):
                min = len(graph[key])

        for node in list(range(len(enemy))):
            if node in selected or len(graph[node]) != min:
                continue

            if min == 0:
                selected.append(node)
                result.append(node)
            else:
                target = graph[node][0]
                selected.append(node)
                selected.append(target)
                result.append((node, target))

                for look_ahead in graph[node]:
                    if look_ahead == target:
                        continue
                    graph[look_ahead].remove(node)
                graph[node] = [target]

                for look_ahead in graph[target]:
                    if look_ahead == node:
                        continue
                    graph[look_ahead].remove(target)
                graph[target] = [node]
            break
    print(len(result))
