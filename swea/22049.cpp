#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int global_max = 0;

bool is_valid(vector<vector<int>> &tree, vector<int> nodes)
{
    vector<bool> visited(tree.size(), false);

    for (int node : nodes)
    {
        for (int next : tree[node])
            visited[next] = true;
    }

    bool result = true;
    for (int node : nodes)
        result &= visited[node];

    return result;
}

void dfs(queue<int> next_nodes, vector<int> used, const vector<int> &values, const vector<vector<int>> &tree1, const vector<vector<int>> &tree2, int acc)
{
    int cur_acc = acc;
    while (!next_nodes.empty())
    {
        int cur_node = next_nodes.front();
        next_nodes.pop();
        used.push_back(cur_node);
        cur_acc += values[cur_node];

        if (global_max < cur_acc)
            global_max = cur_acc;

        for (int next_node : tree1[cur_node])
        {
            if (global_max < cur_acc + values[next_node])
            {
                
            }
        }
    }
}

int problem()
{
    int N;
    scanf("%d", &N);
    vector<int> values(N + 1);
    vector<vector<int>> tree1(N + 1);
    vector<vector<int>> tree2(N + 1);
    vector<bool> visited(N + 1, false);

    // init values
    for (int n = 0; n < N; n++)
    {
        int v;
        scanf("%d", &v);
        values[n] = v;
    }

    // init tree1
    for (int n = 0; n < N - 1; n++)
    {
        int st, ed;
        scanf("%d %d", &st, &ed);
        tree1[st].push_back(ed);
        tree1[ed].push_back(st);
    }

    // init tree2
    for (int n = 0; n < N - 1; n++)
    {
        int st, ed;
        scanf("%d %d", &st, &ed);
        tree2[st].push_back(ed);
        tree2[ed].push_back(st);
    }

    vector<int> used;
    queue<int> next_nodes;
    for (int root = 1; root <= N; root++)
    {
        next_nodes.push(root);
        dfs(next_nodes, used, values, tree1, tree2, 0);
    }

    return global_max;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int result = problem();
        printf("%d\n", result);
    }

    return 0;
}