import sys

cnt_0 = [1, 0]
cnt_1 = [0, 1]

T = int(sys.stdin.readline())
for _ in range(T):
    num = int(sys.stdin.readline())
    if num > len(cnt_0) - 1:
        for i in range(len(cnt_0), num + 1):
            cnt_0.append(cnt_0[i - 1] + cnt_0[i - 2])
            cnt_1.append(cnt_1[i - 1] + cnt_1[i - 2])
        print(cnt_0[num], cnt_1[num])
    else:
        print(cnt_0[num], cnt_1[num])