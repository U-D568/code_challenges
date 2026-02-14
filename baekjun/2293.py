import sys


def main():
    N, K = list(map(int, sys.stdin.readline().split()))
    coins = []
    for _ in range(N):
        val = list(map(int, sys.stdin.readline().split()))[0]
        coins.append(val)
    
    matrix = [0] * (K + 1)
    matrix[0] = 1
    
    for coin in coins:
        for i in range(coin, K + 1):
            matrix[i] += matrix[i - coin]
    print(matrix[-1])


if __name__ == "__main__":
    main()