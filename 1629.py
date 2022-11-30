a, b, c = map(int, input().split())

stack = []
cnt = 0
while b > 1:
    if b % 2 == 0:
        b = b // 2
        stack.append(1)
    else:
        b -= 1
        stack.append(0)

answer = a
while stack:
    i = stack.pop()
    if i == 1:
        answer = answer * answer % c
    else:
        answer = answer * a % c
print(answer % c)
