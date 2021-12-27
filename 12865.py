import sys

N, K = list(map(int, sys.stdin.readline().split()))
W = [-1]
V = [-1]
matrix = [[0] * (K + 1) for _ in range(N + 1)]

for _ in range(N):
    t1, t2 = list(map(int, sys.stdin.readline().split()))
    W.append(t1)
    V.append(t2)

for depth in range(1, N + 1):
    for weight in range(1, K + 1):
        if weight - W[depth] < 0:
            matrix[depth][weight] = matrix[depth - 1][weight]
        else:
            matrix[depth][weight] = max(
                matrix[depth - 1][weight - W[depth]] + V[depth], matrix[depth - 1][weight])

print(matrix[N][K])
