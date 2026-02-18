import sys
from typing import List, Any


def read_ints() -> List[int]:
    return list(map(int, sys.stdin.readline().split()))


def read_line() -> str:
    return sys.stdin.readline()


def init_2d_array(rows: int, cols: int, init: int = 0) -> List[List[int]]:
    return [[init] * cols for _ in range(rows)]


def print_matrix(matrix: List[List[Any]]):
    for row in matrix:
        print(row)
