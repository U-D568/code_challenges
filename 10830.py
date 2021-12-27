import sys
from copy import deepcopy


def print_matrix(mat):
    for r in mat:
        tmp = list(map(lambda x: x % 1000, r))
        print(' '.join(map(str, tmp)))


N, B = list(map(int, sys.stdin.readline().split()))

matrix = []
for _ in range(N):
    matrix.append(list(map(int, sys.stdin.readline().split())))
result = deepcopy(matrix)

stack = []
while B >= 2:
    if B % 2 == 0:
        stack.append(1)
        B /= 2
    else:
        stack.append(0)
        B -= 1

cnt = 1
while len(stack) > 0:
    e = stack.pop()
    tmp = [[0] * N for _ in range(N)]
    if e == 1:
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    di = k - i
                    dj = k - j
                    tmp[i][j] += (result[i][j + dj] * result[i + di][j]) % 1000
        cnt *= 2
    else:
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    di = k - i
                    dj = k - j
                    tmp[i][j] += (result[i][j + dj] * matrix[i + di][j]) % 1000
    result = tmp
print_matrix(result)
