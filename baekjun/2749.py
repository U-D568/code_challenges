n = int(input())

M = 1000000
pisano_seq = []
def pisano_sequence(M):
    global pisano_seq
    previous = 0
    current = 1
    for i in range(M*M):
        previous, current = current, (previous + current) % M
        pisano_seq.append(previous)
        if previous == 0 and current == 1:
            pisano_seq = pisano_seq[-1:] + pisano_seq[0:-1]
            return i + 1
num_of_pisano = pisano_sequence(M)
print(pisano_seq[n % num_of_pisano])