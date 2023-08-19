def solution(N, number):
    answer = 0
    MAX = 8
    values = {5: 1}
    array = [N]
    for i in range(2, 8):
        next_array = []
        while (len(array) != 0):
            element = array.pop()

            plus = element + N
            values[plus] = min(i, values[plus])
            next_array.push(plus)
            if (plus == number):
                return values[plus]

            minus = element - N
            values[minus] = min(i, values[minus])
            if (minus == number):
                return values[minus]
            
            product = element * N
            values[product] = min(i, values[product])
            values[element * N] = min(i, values[element * N])
            values[element / N] = min(i, values[element / N])
            
            ones = 0
            for j in range(0, i):
                ones += 10 * j
            values[ones * N] = i


    return answer

