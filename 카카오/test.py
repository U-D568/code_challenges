import heapq


def solution(n, info):

    answer = []
    heap = []

    dp = [[0] * (n + 1) for _ in range(12)]
    dp2 = [[[False] * 11] * (n + 1) for _ in range(12)]

    enemy_score = 0
    expect_score = [-1]
    arrow_cnt = [-1]

    for score, cnt in enumerate(info[::-1]):
        if cnt == 0:
            expect_score.append(score)
        else:
            expect_score.append(score * 2)
            enemy_score += score
        arrow_cnt.append(cnt + 1)


    for depth in range(1, 12):
        for cnt in range(1, n + 1):
            if cnt - arrow_cnt[depth] < 0:
                dp[depth][cnt] = dp[depth - 1][cnt]
                dp2[depth][cnt] = list(dp2[depth - 1][cnt])
            else:
                if dp[depth - 1][cnt - arrow_cnt[depth]] + expect_score[depth] > dp[depth - 1][cnt]:
                    dp[depth][cnt] = dp[depth - 1][cnt -
                                                   arrow_cnt[depth]] + expect_score[depth]

                    temp = [False] * 11
                    temp[depth - 1] = True
                    for i in range(11):
                        temp[i] = temp[i] or dp2[depth - 1][cnt - arrow_cnt[depth]][i]
                    dp2[depth][cnt] = list(temp)
                else:
                    dp[depth][cnt] = dp[depth - 1][cnt]
                    dp2[depth][cnt] = list(dp2[depth - 1][cnt])

    for idx, is_shot in enumerate(dp2[-1][-1]):
        if is_shot:
            answer.append(arrow_cnt[idx + 1])
        else:
            answer.append(0)

    answer = answer[::-1]

    cnt = 0
    for i in answer:
        cnt += i
    if cnt < n:
        answer[-1] += n - cnt

    if enemy_score < dp[-1][-1]:
        return answer
    return [-1]


n = 9
info = [0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1]

print(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]))
[1,1,1,1,1,1,1,1,0,0,2]