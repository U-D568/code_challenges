import sys


def read_line() -> str:
    return sys.stdin.readline().strip()


def main():
    str1 = read_line()
    str2 = read_line()

    rows = len(str1) + 1
    cols = len(str2) + 1
    matrix = [[0] * (cols) for _ in range(rows)]

    for i in range(1, rows):
        for j in range(1, cols):
            ch1 = str1[i - 1]
            ch2 = str2[j - 1]
            if ch1 == ch2: # 비교하는 문자가 같으면 매칭하기 전 LCS에 +1
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j - 1] + 1)
            else: # 다르면 이전에 매칭한 LCS들 중에서 최대 값 선택
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j])
    print(matrix[-1][-1])


if __name__ == "__main__":
    main()
