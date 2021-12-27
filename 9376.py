import sys

T = int(input())

def print_jail():
    for row in jail:
        print(row)
    print()



H, W = list(map(int, sys.stdin.readline().split()))
jail = []
prisoner = []
goal = []
visited = [[False] * W for _ in range(H)]



for i in range(H):
    row = sys.stdin.readline().rstrip()
    jail.append(row)
    if '$' in row:
        for j, ch in enumerate(row):
            if ch == '$':
                prisoner.append((i, j))


