import sys
from typing import List


def read_ints() -> List[int]:
    return list(map(int, sys.stdin.readline().split()))


def main():
    N = read_ints()[0]
    ary = read_ints()

    ascending = [0] * (N + 1)
    for i in range(0, N):
        while not (stack[-1] < ary[i]):
            stack.pop()
        stack.append(ary[i])
        ascending[i] = len(stack) - 1
    print(ascending)

    descending = [0] * N
    stack = [0]
    for i in range(N - 1, -1, -1):
        while not (stack[-1] < ary[i]):
            stack.pop()
        stack.append(ary[i])
        descending[i] = len(stack) - 1
    print(descending)

    total = [-1] * N
    for i in range(N):
        total[i] = ascending[i] + descending[i] - 1
    print(total)
    print(max(total))
    


if __name__ == "__main__":
    main()
