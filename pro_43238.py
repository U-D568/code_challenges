def solution(n, times):
    left  = 0
    right = max(times) * n
    answer = 0

    while left <= right:
        mid = (left + right) // 2
        cnt = 0
        for time in times:
            cnt += mid // time

            if cnt >= n:
                break
        
        if cnt >= n:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer


solution(6, [7, 28])