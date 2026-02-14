import time

t = time.time()
N = int(input())


columns = [0 for _ in range(N)]
NE_diagonal = [0 for _ in range(2 * N - 1)]
SE_diagonal = [0 for _ in range(2 * N - 1)]


def search(node, depth):
    global columns
    global NE_diagonal
    global SE_diagonal
    global cnt

    columns[node] = 1
    NE_diagonal[node + depth] = 1
    SE_diagonal[(N - 1) + depth - node] = 1

    if depth == N - 1:
        cnt += 1
    else:
        for col in range(N):
            if columns[col] == 1:
                continue
            if NE_diagonal[depth + col + 1] == 1:
                continue
            if SE_diagonal[(N - 1) + depth - col + 1] == 1:
                continue
            search(col, depth + 1)
    columns[node] = 0
    NE_diagonal[node + depth] = 0
    SE_diagonal[(N - 1) + depth - node] = 0


cnt = 0
visit_cnt = 0
for i in range(N):
    search(i, 0)

print(cnt)
print('time:', time.time() - t, 's')
