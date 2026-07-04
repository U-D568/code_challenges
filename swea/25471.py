import math


def problem():
    N = int(input())
    if N % 2 == 0:
        if N & (N - 1) == 0: # 2의 거듭제곱 여부 검사
            power = math.log2(N)
            if power % 2 == 0:
                print("A")
            else:
                print("B")
        else:
            print("A")
    else:
        print("B")


T = int(input())
for _ in range(T):
    problem()


# 숫자를 차례로 증가시키면서 승리 조건을 계산하면 귀납적으로 다음 규칙이 성립하게 된다.
# (p는 홀수)
# p -> B 승리
# 2^n * p = A 승리
# 2^짝수 = A 승리
# 2^홀수 = B 승리
# 위 조건을 바탕으로 코드를 작성하여 문제를 풀이한다.
