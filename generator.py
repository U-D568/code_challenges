import random

with open('input.txt', 'w') as f:
    f.write('10000 5000\n')
    f.write('1\n')

    cnt1 = 1
    cnt2 = 0

    root = 1
    for idx, cost in enumerate(range(10, 0, -1)):
        if idx == 0:
            f.write('{} {} {}\n'.format(root, idx + 2, cost * 2))
            cnt2 += 1
        else:
            f.write('{} {} {}\n'.format(root, idx + 2, cost))
            f.write('{} {} {}\n'.format(idx + 2, root + 1, cost))
            cnt2 += 2
    
    for i in range(0, 50000):
        root = 2 + i * 10
        for idx, cost in enumerate(range(10, 0, -1)):
            if idx == 0:
                f.write('{} {} {}\n'.format(root, root + idx + 10, cost * 2))
                cnt2 += 1
            else:
                f.write('{} {} {}\n'.format(root, root + idx + 10, cost))
                f.write('{} {} {}\n'.format(root + idx + 10, root + 10, cost))
                cnt2 += 2
        cnt1 += 10
    print(cnt1, cnt2)