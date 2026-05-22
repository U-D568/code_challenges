def problem():
    N = int(input())
    nodes = [0] * N
    for _ in range(N - 1):
        a, b = list(map(int, input().split()))
        nodes[a - 1] += 1
        nodes[b - 1] += 1
    
    cnt = 0
    for n in nodes:
        cnt += abs(2 - n)
    cnt = (cnt - 2) // 2
    print(cnt)

T = int(input())
for _ in range(T):
    problem()



# 링크: https://swexpertacademy.com/main/code/problem/problemDetail.do?passFilterYn=Y&contestProbId=AZyNVrgKAVXHBIRj&categoryId=AZyNVrgKAVXHBIRj&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=P&pageSize=10&pageIndex=1
# 풀이

# 체인의 규칙은 각 노드에서 연결된 간선의 수를 카운트 했을 때 1이 2개, 나머지는 2인 것을 이용하여 풀었습니다.
# 각 노드에 연결된 간선의 수를 카운트한 다음 2와 뺀 값의 절댓값을 모두 합한 다음 2를 빼고 2로 나누면 최소 변경 횟수를 구할 수 있습니다.