import math
from typing import List

B = 0
min_diff = math.inf


def problem(t):
    global B, min_diff
    N, B = list(map(int, input().split()))
    S = list(map(int, input().split()))
    cal(0, 0, S)
    print(f"#{t + 1} {min_diff}")


def cal(total: int, index: int, heights: List[int]):
    global min_diff, B
    if index == len(heights):
        diff = abs(B - total)
        if diff < min_diff and B <= total:
            min_diff = diff
        return
    current = heights[index]

    # insert
    cal(total + current, index + 1, heights)

    # pass
    cal(total, index + 1, heights)


T = int(input())
for t in range(T):
    min_diff = math.inf
    problem(t)
