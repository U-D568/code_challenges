import math

def solution() -> int:
    N = int(input())
    min_val = math.inf
    max_val = -1
    values = list(map(int, input().split()))
    for val in values:
        min_val = min(min_val, val)
        max_val = max(max_val, val)
    return max_val - min_val

def main():
    T = int(input())
    for t in range(T):
        print(f"#{t + 1} {solution()}")


if __name__ == "__main__":
    main()
