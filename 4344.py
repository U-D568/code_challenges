import sys

T = int(sys.stdin.readline())

for _ in range(T):
    row = list(map(int, sys.stdin.readline().split()))
    length = row[0]
    cnt = 0

    mean = sum(row[1:]) / length
    
    for i in row[1:]:
        if i > mean:
            cnt += 1
    print('%.3f%%' % (cnt / length * 100))
    