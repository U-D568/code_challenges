import math

def get_column(matrix, i):
    return [x[i] for x in matrix]


def max_args(array):
    max_val = max(array)
    return array.index(max_val)


def swap_row(matrix, i, j):
    temp = list(matrix[i])
    matrix[i] = matrix[j]
    matrix[j] = temp


def upper_triangular_matrix(matrix):
    n_cols = len(matrix[0])
    n_rows = len(matrix)
    sign = 1
    
    for i_col in range(n_cols - 1):
        col = get_column(matrix, i_col)
        p_v = max(col, key=abs) # pivot value
        p_i = col.index(p_v) # pivot index
        if i_col != p_i:
            swap_row(matrix, i_col, p_i)
            sign *= -1

        for i_row in range(i_col + 1, n_rows):
            modifier = matrix[i_row][i_col] / p_v
            for i in range(i_col, n_cols):
                matrix[i_row][i] -= modifier * matrix[i_col][i]
    
    return sign, matrix


def sub_diag_matrix(matrix, val):
    for i in range(len(matrix)):
        matrix[i][i] -= val


def det_from_triangular_matrix(matrix, sign, C):
    n = len(matrix)
    det = 1
    for i in range(n):
        det *= math.fmod(matrix[i][i], C)
    return det * sign

def copy_matrix(matrix):
    return [row[:] for row in matrix]

def print_matrix(matrix):
    for row in matrix:
        print(row)

def test_case():
    C = 998244353
    N, Q = list(map(int, input().split()))
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().split())))
    queries = list(map(int, input().split()))

    answer = []


    for q in queries:
        _matrix = copy_matrix(matrix)
        sub_diag_matrix(_matrix, q)
        sign, _matrix = upper_triangular_matrix(_matrix)
        det = det_from_triangular_matrix(_matrix, sign, C)
        answer.append(int(det))
    print(" ".join(list(map(str, answer))))


T = int(input())
for _ in range(T):
    test_case()
