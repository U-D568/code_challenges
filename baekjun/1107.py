import sys
import itertools

chanel = int(sys.stdin.readline())
num_broken = int(sys.stdin.readline())
if num_broken != 0:
    broken = list(map(int, sys.stdin.readline().split()))

not_broken = []
for i in range(10):
    if i in broken:
        continue
    not_broken.append(i)
not_broken.sort()

def permutation(numbers):
    result = itertools.combinations(numbers)
    print(result)


def search(length, numbers):
    pass

permutation(list(range(10)))