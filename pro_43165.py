import math


def solution(numbers, target):
    layer = []
    layer.append(numbers[0])
    count = 0
    for num, index in enumerate(numbers[1:]):
        next_layer = []
        while len(layer) > 0:
            node = layer.pop()
            next_layer.append(node + num)
            next_layer.append(node - num)
            if index == len(numbers) - 1:
                if node + num == target:
                    count += 1
                if node - num == target:
                    count += 1
        layer = list(next_layer)

    return count


print(solution([1, 1, 1, 1, 1], 3))
