import sys
from collections import deque

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())

    in_vertex = {}
    out_vertex = {}
    rank = {}
    root = deque()

    for idx, val in enumerate(list(map(int, sys.stdin.readline().split()))):
        rank[val] = idx + 1

    M = int(sys.stdin.readline())

    for i in range(N):
        in_vertex[i + 1] = []
        out_vertex[i + 1] = []

    for _ in range(M):
        up, down = list(map(int, sys.stdin.readline().split()))
        in_vertex[down].append(up)
        out_vertex[up].append(down)
    
    