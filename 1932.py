import sys

n = int(sys.stdin.readline())
tree = []

for _ in range(n):
    tree.append(list(map(int, sys.stdin.readline().split())))

depth = n - 1
while depth > 0:
    buffer = [0] * len(tree[depth - 1])
    for y in range(len(tree[depth])):
        for dy in (-1, 0):
            y2 = y + dy
            if y2 < 0 or y2 >= len(tree[depth - 1]):
                continue
            buffer[y2] = max(buffer[y2], tree[depth - 1][y2] + tree[depth][y])
    tree[depth - 1] = buffer
    depth -= 1

print(tree[0][0])
