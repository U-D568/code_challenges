N, R = map(int, input().split())
NUM = 1000000007
N = N % NUM
R = R % NUM

cache = [[0] * (R + 1) for _ in range(N + 1)]

for n in range(N + 1):
    cache[n][0] = 1
for r in range(R + 1):
    cache[r][r] = 1

for i in range(1, N + 1):
    for j in range(1, R + 1):
        if i < j:
            continue
        cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j]

print(cache[N][R])
