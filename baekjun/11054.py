import sys
from typing import List


def read_ints() -> List[int]:
    return list(map(int, sys.stdin.readline().split()))


def main():
    N = read_ints()[0]
    ary = [0]
    ary.extend(read_ints())

    ascending = [0] * (N + 1)
    for i in range(1, N + 1):
        for j in range(i):
            if ary[j] < ary[i]:
                ascending[i] = max(ascending[i], ascending[j] + 1)

    descending = [0] * (N + 1)
    for i in range(N, 0, -1):
        for j in range(N, i, -1):
            if ary[j] < ary[i]:
                descending[i] = max(descending[i], descending[j] + 1)

    total = [0] * N
    for i in range(N):
        total[i] = ascending[i + 1] + descending[i + 1]
    print(max(total))
    


if __name__ == "__main__":
    main()
