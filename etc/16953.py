x, y = map(int, input().split())

cnt = 0
while True:
    if x == y:
        print(cnt + 1)
        break
    elif x > y:
        print(-1)
        break

    if y % 10 == 1:
        cnt += 1
        y = (y - 1) // 10
    elif y % 2 == 0:
        cnt += 1
        y = y // 2
    else:
        print(-1)
        break
