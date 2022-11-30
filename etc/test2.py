import math


def is_prime(x):
    if x < 2:
        return False
    elif x == 2:
        return True
    else:
        for i in range(2, int(math.sqrt(x)) + 1):
            if x % i == 0:
                return False
        return True


def solution(n, k):
    answer = 0

    i = 0
    new_n = ''
    while n > 0:
        n, q = divmod(n, k)
        new_n += str(q)
    
    new_n = int(new_n[::-1])

    for i in str(new_n).split('0'):
        if i == '':
            continue
        else:
            if is_prime(int(i)):
                answer += 1

    return answer


print(solution(437674, 3))
