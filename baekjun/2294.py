import sys
import math


def main():
    N, K = list(map(int, sys.stdin.readline().split()))

    coins = []
    for _ in range(N):
        coins.append(list(map(int, sys.stdin.readline().split()))[0])
    
    matrix = [math.inf] * (K + 1)
    matrix[0] = 0
    
    for c in coins:
        for i in range(c, K + 1):
            matrix[i] = min(matrix[i], matrix[i - c] + 1)

    answer = matrix[-1]
    if answer == math.inf:
        print(-1)
    else:
        print(answer)


if __name__ == "__main__":
    main()
