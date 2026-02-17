import sys
from typing import List
import math


def read_ints() -> List[int]:
    return list(map(int, sys.stdin.readline().split()))


def make_number(depth, max_depth, numbers, values):
    if max_depth == depth:
        return values

    next_values = []
    for num in numbers:
        for v in values:
            new_val = v * 10 + num
            if new_val > 1000000:
                continue
            next_values.append(new_val)
    return make_number(depth+1, max_depth, numbers, next_values)



def main():
    target = read_ints()[0]
    N = read_ints()[0]
    not_use = read_ints() if N != 0 else []
    buttons = []
    for i in range(10):
        if i in not_use:
            continue
        buttons.append(i)

    from_init = abs(target - 100)

    length = len(str(target))
    candidates = []
    if length > 1:
        res = make_number(0, length - 1, buttons, [0])
        candidates.extend(res)
        res = make_number(length - 1, length, buttons, res)
        candidates.extend(res)
    else:
        res = list(buttons)
        candidates.extend(buttons)
    res = make_number(length, length + 1, buttons, res)
    candidates.extend(res)

    counts = [from_init]
    min_diff = math.inf
    min_val = -1
    for channel in candidates:
        diff = abs(target - channel)
        if diff < min_diff:
            min_diff = diff
            min_val = channel
        counts.append(len(str(channel)) + abs(target - channel))
    print(min(counts))


if __name__ == "__main__":
    main()
