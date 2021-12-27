import sys
from collections import deque


def print_maze():
    for row in maze:
        print(''.join(row))


N, M = map(int, input().split())
maze = []
red_visisted = [[False] * M for _ in range(N)]
blud_visisted = [[False] * M for _ in range(N)]
red_queue = deque()
blue_queue = deque()
goal = (0, 0)
red = (0, 0)
blud = (0, 0)

dx = (1, -1, 0, 0)
dy = (0, 0, 1, -1)

for x in range(N):
    row = list(input().rstrip())
    maze.append(row)
    for y, e in enumerate(row):
        if e == 'R':
            red = (x, y)
        elif e == 'B':
            blue = (x, y)
        elif e == 'O':
            goal = (x, y)


def bfs():
    while red_queue:
        x, y = red_queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if maze[nx][ny] == 'O':
                return True
            elif maze[nx][ny] == '.':
                while True:
                    nx += dx[i]
                    ny += dy[i]