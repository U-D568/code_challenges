def problem() -> int:
    N = int(input()) // 10
    dp = [0] * N
    dp[0] = 1
    dp[1] = 3

    for i in range(2, N):
        dp[i] = dp[i - 1] + dp[i - 2] * 2

    return dp[-1]


def main():
    T = int(input())
    for t in range(1, T + 1):
        res = problem()
        print(f"#{t} {res}")


if __name__ == "__main__":
    main()
