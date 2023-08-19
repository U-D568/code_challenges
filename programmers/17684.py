# https://school.programmers.co.kr/learn/courses/30/lessons/17684?language=python3
# LZW algorithm

# ord('A') == 65
def solution(msg):
    answer = []
    word_dict = {}
    pivot = 0
    next_pivot = 1
    for char in range(0, 26):
        word_dict[chr(ord('A') + char)] = char + 1

    while pivot <= len(msg):
        word = msg[pivot:next_pivot]
        skip = False
        while word in word_dict:
            if next_pivot == len(msg):
                skip = True
                break
            next_pivot += 1
            word = msg[pivot:next_pivot]

        if not skip:
            word_dict[word] = len(word_dict) + 1
            answer.append(word_dict[word[:-1]])
            pivot = next_pivot - 1
        else:
            answer.append(word_dict[word])
            pivot = next_pivot + 1
    return answer


if __name__ == '__main__':
    print(solution('A'))