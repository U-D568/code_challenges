import sys

N = int(sys.stdin.readline())
cost = list(map(int, sys.stdin.readline().split()))
reward = list(map(int, sys.stdin.readline().split()))

health = 100
happiness = 0
min_cost = min(cost)

def search(node, cur_health, cur_happiness):
    global happiness
    global min_cost

    remain_health = cur_health - cost[node]
    if remain_health > 0:
        happiness = max(happiness, cur_happiness + reward[node])
    if remain_health >= min_cost:
        for i in range(node + 1, N):
            search(i, remain_health, cur_happiness + reward[node])

for i in range(N):
    search(i, 100, 0)

print(happiness)