import sys

N, M = map(int, sys.stdin.readline().split())

grades = []
values = []
for _ in range(N):
    grade, val = sys.stdin.readline().split()
    val = int(val)
    if len(values) !=0 and values[-1] == val:
        continue
    grades.append(grade)
    values.append(val)

for i in range(M):
    val = int(sys.stdin.readline().rstrip())
    st = 0
    ed = len(values) - 1
    result = 0
    
    while st <= ed:
        mid = (st + ed) // 2
        if values[mid] >= val:
            result = mid
            ed = mid - 1
        else:
            st = mid + 1
    print(grade[result])

def bs(li, n):
    s, e = 0, len(li)-1
    res = 0
    while s <= e:
        m = (s+e)//2
        if int(li[m][1]) >= n:
            e = m-1
            res = m
        else:
            s = m+1
    return res