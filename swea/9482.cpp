#include <iostream>
#include <vector>

using namespace std;

bool is_clique(vector<vector<int>> graph, vector<bool> &visited, int st_node)
{
    if (graph[st_node].size() == graph.size() - 1)
        return false;

    int init_edges = graph[st_node].size();
    int sum = init_edges;
    for (int n : graph[st_node])
    {
        sum += graph[n].size();
        visited[n] = true;
    }

    
    if (sum == (init_edges + 1) * init_edges)
        return true;

    return false;
}

bool problem()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1);
    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int clique_count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        if (!is_clique(graph, visited, i))
            return false;
        clique_count++;
    }

    if (clique_count != 2)
        return false;

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int i = 0; i < TC; i++)
    {
        string result = problem() ? "DA" : "NE";
        printf("#%d %s\n", i + 1, result.c_str());
    }

    return 0;
}