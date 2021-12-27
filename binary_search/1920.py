import sys
from collections import deque

_ = sys.stdin.readline()
a = list(map(int, sys.stdin.readline().split()))
_ = sys.stdin.readline()
b = list(map(int, sys.stdin.readline().split()))

a.sort()
b = deque(b)
while b:
    n = b.popleft()
    st = 0
    ed = len(a) - 1
    while True:
        mid = (ed + st) // 2
        if a[mid] == n:
            print(1)
            break
        elif a[mid] > n:
            ed = mid - 1
        elif a[mid] < n:
            st = mid + 1

        if st > ed:
            print(0)
            break
