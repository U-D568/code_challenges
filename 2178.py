import sys
from collections import deque

maze = []
R, C = list(map(int, sys.stdin.readline().split()))

for i, row in enumerate(range(R)):
    maze.append(list(map(int, list(sys.stdin.readline().rstrip()))))

queue = deque([(0, 0)])
while queue:
    x, y = queue.popleft()
    if x == R - 1 and y == C - 1:
        print(maze[R - 1][C - 1])
        break

    for dx, dy in zip([0, 0, 1, -1], [1, -1, 0, 0]):
        if x + dx < 0 or x + dx >= R or y + dy < 0 or y + dy >= C:
            continue
        if maze[x + dx][y + dy] == 1:
            maze[x + dx][y + dy] += maze[x][y]
            queue.append((x + dx, y + dy))
