def solution():
    N = int(input())
    values = list(map(int, input()))
    buffer = {}
    max_cnt = -1
    max_val = -1
    for key in values:
        val = buffer.get(key, 0) + 1
        buffer[key] = val
        if val > max_cnt:
            max_cnt = val
            max_val = key
        elif val == max_cnt:
            max_val = key if key > max_val else max_val
    return max_val, max_cnt

T = int(input())
for t in range(T):
    res = solution()
    print(f"#{t + 1} {res[0]} {res[1]}")
