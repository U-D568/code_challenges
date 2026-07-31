try:
    cnt, prod = 1, 1
    while True:
        N = int(input())
        if cnt % 2 == 0:
            print(f"x * y = {prod * N}")
        else:
            prod = N
        cnt += 1
except:
    print("숫자가 아닙니다. 재입력하세요.")