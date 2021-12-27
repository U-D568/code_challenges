import sys
from collections import deque


def print_pond():
    for row in pond:
        print(''.join(row))
    print('')


def melt_pond():
    while ice:
        x, y = ice.popleft()
        if pond[x][y] == 'X':
            pond[x][y] = '.'

        for dx, dy in zip([0, 0, 1, -1], [1, -1, 0, 0]):
            i, j = x + dx, y + dy
            if i < 0 or i >= R or j < 0 or j >= C:
                continue

            if not ice_visisted[i][j]:
                ice_visisted[i][j] = True
                if pond[i][j] == 'X':
                    temp_ice.append((i, j))


def bfs():
    while queue:
        x, y = queue.popleft()

        for dx, dy in zip([0, 0, 1, -1], [1, -1, 0, 0]):
            i, j = x + dx, y + dy
            if i < 0 or i >= R or j < 0 or j >= C:
                continue

            if not visited[i][j]:
                visited[i][j] = True
                if i == swan[1][0] and j == swan[1][1]:
                    return True
                elif pond[i][j] == '.':
                    queue.append((i, j))
                elif pond[i][j] == 'X':
                    temp_queue.append((i, j))
    return False


R, C = list(map(int, sys.stdin.readline().split()))

day = 0
pond = []
visited = [[False] * C for _ in range(R)]
ice_visisted = [[False] * C for _ in range(R)]
swan = []

queue = deque()
temp_queue = deque()
ice = deque()
temp_ice = deque()

for x in range(R):
    row = list(sys.stdin.readline().rstrip())
    pond.append(row)
    for y, val in enumerate(row):
        if val == 'L':
            swan.append((x, y))
            ice.append((x, y))
            pond[x][y] = '.'
        elif val == '.':
            ice.append((x, y))
            ice_visisted[x][y] = True

queue.append(swan[0])
visited[swan[0][0]][swan[0][1]] = True

while True:
    melt_pond()
    if bfs():
        print(day)
        break
    day += 1
    queue = temp_queue
    ice = temp_ice
    temp_queue = deque()
    temp_ice = deque()
