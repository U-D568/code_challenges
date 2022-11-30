import sys
from collections import deque

N, M = list(map(int, sys.stdin.readline().split()))

spies = []
party_info = []
guest_book = dict()
is_checked = [False] * (N + 1)
black_list = dict()

row = list(map(int, sys.stdin.readline().split()))
if row[0] > 0:
    spies += row[1:]

for spy in spies:
    is_checked[spy] = True

for i in range(1, N + 1):
    guest_book[i] = []

for i in range(M):
    row = list(map(int, sys.stdin.readline().split()))
    party_info.append(row[1:])
    for guest in row[1:]:
        guest_book[guest].append(i)

queue = deque(spies)
while queue:
    spy = queue.popleft()
    for party in guest_book[spy]:
        black_list[party] = True
        for guest in party_info[party]:
            if not is_checked[guest]:
                is_checked[guest] = True
                queue.append(guest)

print(M - len(black_list.keys()))
