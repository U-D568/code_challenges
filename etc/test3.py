def solution(board, skill):
    answer = 0

    for row in skill:
        for i in range(row[1], row[3] + 1):
            for j in range(row[2], row[4] + 1):
                if row[0] == 1:
                    board[i][j] -= row[5]
                else:
                    board[i][j] += row[5]
    
    cnt = 0
    for i in board:
        for j in i:
            if j > 0:
                cnt += 1
    answer = cnt

    print(answer)
    return answer


solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]], [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]])