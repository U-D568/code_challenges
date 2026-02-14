import sys
from collections import deque

lab = []
R, C = list(map(int, sys.stdin.readline().split()))

for i, row in enumerate(range(R)):
    lab.append(list(map(int, list(sys.stdin.readline().rstrip()))))

queue = deque([(0, 0)])
while queue:
    x, y = queue.popleft()
    if x == R - 1 and y == C - 1:
        print(lab[R - 1][C - 1])
        break

    for dx, dy in zip([0, 0, 1, -1], [1, -1, 0, 0]):
        if x + dx < 0 or x + dx >= R or y + dy < 0 or y + dy >= C:
            continue
        if lab[x + dx][y + dy] == 1:
            lab[x + dx][y + dy] += lab[x][y]
            queue.append((x + dx, y + dy))
