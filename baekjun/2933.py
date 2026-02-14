import sys
from collections import deque

dx = (1, -1, 0, 0)
dy = (0, 0, 1, -1)


def print_cave():
    for row in cave:
        print(''.join(row))


def bfs(root):
    global bottom, top, cluster, width
    temp_cluster = deque()
    queue = deque([root])

    temp_top = [R] * C
    temp_bottom = [0] * C

    min_col = C
    max_col = 0
    min_row = 0

    while queue:
        x, y = queue.popleft()

        temp_cluster.append((x, y))
        min_col = min(min_col, y)
        max_col = max(max_col, y)
        temp_top[y] = min(temp_top[y], x)
        temp_bottom[y] = max(temp_bottom[y], x)

        min_row = max(x, min_row)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= R or ny < 0 or ny >= C:
                continue
            if not visisted[nx][ny]:
                visisted[nx][ny] = True
                if cave[nx][ny] == 'x':
                    queue.append((nx, ny))

    if min_row == R - 1:
        top = temp_top
        return False
    else:
        bottom = temp_bottom
        cluster = temp_cluster
        width = (min_col, max_col)
        return True


def fall():
    tmp = deque()

    height = R
    for c in range(width[0], width[1] + 1):
        st = bottom[c]
        cnt = 0
        for i in range(st + 1, R):
            cnt += 1
            if cave[i][c] == 'x':
                cnt -= 1
                break
        height = min(cnt, height)

    while cluster:
        x, y = cluster.popleft()
        tmp.append((x, y))
        cave[x][y] = '.'

    while tmp:
        x, y = tmp.popleft()
        cave[x + height][y] = 'x'


R, C = map(int, input().split())

cave = []
for _ in range(R):
    row = list(input().rstrip())
    cave.append(row)

N = int(input())
heights = list(map(int, input().split()))
for n, val in enumerate(heights):
    visisted = [[False] * C for _ in range(R)]
    bottom = []
    top = []
    cluster = deque()
    width = (0, 0)
    isdivided = False

    isleft = n % 2 == 0
    if isleft:
        col = 0
    else:
        col = C - 1
    row = R - val

    while col >= 0 and col < C:
        if cave[row][col] == 'x':
            cave[row][col] = '.'
            for i in range(4):
                nx = row + dx[i]
                ny = col + dy[i]
                if nx < 0 or nx >= R or ny < 0 or ny >= C:
                    continue

                if not visisted[nx][ny] and cave[nx][ny] == 'x':
                    visisted[nx][ny] = True
                    isdivided |= bfs((nx, ny))
            break
        elif isleft:
            col += 1
        elif not isleft:
            col -= 1

    if isdivided:
        fall()

print_cave()
