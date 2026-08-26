def inner_product(v1, v2):
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]
 
 
def outter_product(v1, v2):
    return (
        v1[1] * v2[2] - v1[2] * v2[1],
        v1[2] * v2[0] - v1[0] * v2[2],
        v1[0] * v2[1] - v1[1] * v2[0],
    )
 
 
def vector_subtract(v1, v2):
    return (v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2])
 
 
def problem():
    N = int(input())
    points = []
    for _ in range(N):
        points.append(list(map(int, input().split())))
 
    if N <= 3:
        return True
 
    v1 = vector_subtract(points[1], points[0])
 
    idx = 2
    anchor = (0, 0, 0)
    while idx < N:
        v2 = vector_subtract(points[idx], points[0])
        anchor = outter_product(v1, v2)
        if anchor[0] != 0 or anchor[1] != 0 or anchor[2] != 0:
            break
        idx += 1
     
    if anchor[0] == 0 and anchor[1] == 0 and anchor[2] == 0:
        return True
 
    for i in range(idx + 1, N):
        pi = points[i]
        vi = vector_subtract(pi, points[0])
        if inner_product(anchor, vi) != 0:
            return False
    return True
 
 
T = int(input())
for t in range(T):
    val = "TAK" if problem() else "NIE"
    print(f"#{t + 1} {val}")