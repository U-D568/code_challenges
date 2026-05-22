def problem():
    N = int(input())
    weights = list(map(int, input().split()))
    weights = sorted(weights)

    # find min mst
    min_mst = 0
    for v in weights[:N - 1]:
        min_mst += v

    # find max mst
    indices = [0]
    for i in range(1, N - 1):
        prev = prev if i > 1 else 1
        prev = prev + i
        indices.append(prev - 1)

    max_mst = 0
    for idx in indices:
        max_mst += weights[idx]

    print(min_mst, max_mst)

T = int(input())
for _ in range(T):
    problem()



# 링크: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZz7FPpqAUnHBIRj
# 풀이

# 문제는 주어진 간선으로 만들 수 있는 모든 그래프 중에서 가장 작은 MST와 가장 큰 MST를 구해야 합니다.
# 문제에서 최대 간선의 수가 4950으로 정렬을 써도 상관없다고 판단했습니다.
# 최소 MST는 정렬한 값에서 N-1 번째 값들을 합하면 구할 수 있습니다.
# 최대 MST을 구하기 위해서 아래의 조건들을 만족해야 합니다.
# - MST를 만족해야 한다.
# - 최대한 많은 최소값들이 사이클에 포함되어야 한다.
# 이를 구현하기 위해서 간선을 하나씩 추가하며 그래프를 그립니다. 노드를 추가할 때는 더 이상 간선을 그릴 수 없을 때만 추가합니다. 그러면 아래의 순서대로 천천히 그릴 수 있습니다.
# 1. 2개의 노드와 하나의 간선을 그립니다. (A, B)
# 2. 더 이상 간선을 추가할 수 없어 노드를 추가하고 간선을 만듭니다. (B, C)
# 3. 사이클을 형성하도록 하나의 간선을 추가합니다. (A, C)
# 4. 더 이상 간선을 추가할 수 없어 노드를 추가하고 간선을 만듭니다. (C, D)
# 5. 사이클을 형성하도록 간선을 추가합니다. (A, D)
# 6. 사이클을 형성하도록 간선을 추가합니다. (B, D)
# 7. 더 이상 간선을 추가할 수 없어 노드를 추가하고 간선을 만듭니다. (D, E)
# 8. 사이클을 형성하도록 간선을 추가합니다. (A, E)
# 9. 사이클을 형성하도록 간선을 추가합니다. (B, E)
# 10. 사이클을 형성하도록 간선을 추가합니다. (C, E
# ...

# 위의 순서대로 쭉 나열했을 때 규칙을 보면 새로운 노드를 생성할 때 추가하는 노드만 사이클이 발생하지 않는 간선이 됩니다.
# 즉 노드를 추가할 때의 위치에 있는 간선 값들을 가져오면 최대 MST를 형성할 수 있습니다. 왜냐하면 사이클이 발생하는 간선에는 최대한 낮은 값들을 할당시켜 최대 MST를 유도합니다.
# 이를 점화식으로 나타내면
# a_0 = 1
# a_n = a_{n-1} + n
# 으로 나타낼 수 있습니다.
# 위 점화식을 통해 사이클이 발생하지 않는 간선들을 합하여 최대 MSt를 구할 수 있습니다.