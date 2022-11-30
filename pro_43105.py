def solution(triangle):
    answer = 0
    for layer in range(1, len(triangle)):
        for index in range(len(triangle[layer])):
            if index == 0:
                triangle[layer][index] += triangle[layer - 1][index]
            elif index == len(triangle[layer]) - 1:
                triangle[layer][index] += triangle[layer - 1][index - 1]
            else:
                triangle[layer][index] += max(triangle[layer - 1][index], triangle[layer - 1][index - 1])
    answer = max(triangle[-1])
    return answer

print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))