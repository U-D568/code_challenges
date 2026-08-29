#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct Node
{
    int index;
    int weight;
    bool operator<(const Node &other) const
    {
        return this->weight > other.weight;
    }
};

int problem()
{
    int N, E;
    scanf("%d %d", &N, &E);
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1));
    vector<int> visited(N + 1, numeric_limits<int>::max());
    priority_queue<Node> min_heap;

    int st, end, time;
    for (int e = 0; e < E; e++)
    {
        scanf("%d %d %d", &st, &end, &time);
        if (graph[st][end] == -1)
            graph[st][end] = time;
        else
            graph[st][end] = min(graph[st][end], time);
    }

    min_heap.push(Node{0, 0});
    visited[0] = 0;
    while (!min_heap.empty())
    {
        Node node = min_heap.top();
        min_heap.pop();

        if (node.index == N)
            return node.weight;

        for (int i = 0; i <= N; i++)
        {
            if (i == node.index)
                continue;
            if (graph[node.index][i] == -1)
                continue;
            if (node.weight + graph[node.index][i] < visited[i])
            {
                visited[i] = node.weight + graph[node.index][i];
                min_heap.push(Node{i, visited[i]});
            }
        }
    }

    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int result = problem();
        printf("#%d %d\n", t + 1, result);
    }

    return 0;
}