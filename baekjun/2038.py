import time

st = time.time()
n = int(input())

def golomb(a):
    if a == 1:
        return 1
    else:
        return 1 + golomb(a - golomb(golomb(a - 1)))

print(golomb(n))
print(time.time() - st)