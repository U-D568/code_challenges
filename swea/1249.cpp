#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <string>

using namespace std;

struct Node
{
    int row;
    int col;
    int weight;

    bool operator<(const Node &other) const
    {
        return this->weight > other.weight;
    }
};

bool is_valid(int row, int col, int N)
{
    return !(row < 0 || col < 0 || row >= N || col >= N);
}

int problem()
{
    int N;
    scanf("%d", &N);
    priority_queue<Node> min_heap;
    vector<vector<int>> field(N, vector<int>(N));
    vector<vector<int>> visited(N, vector<int>(N, numeric_limits<int>::max()));

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            int val;
            scanf("%1d", &val);
            field[r][c] = val;
        }
    }

    min_heap.push(Node{0, 0, field[0][0]});
    visited[0][0] = field[0][0];
    while (!min_heap.empty())
    {
        Node node = min_heap.top();
        min_heap.pop();

        if (node.row == N - 1 && node.col == N - 1)
            return node.weight;

        for (int dir = 0; dir < 4; dir++)
        {
            int new_row = node.row + dr[dir];
            int new_col = node.col + dc[dir];

            if (!(is_valid(new_row, new_col, N)))
                continue;

            int new_weight = node.weight + field[new_row][new_col];
            if (new_weight < visited[new_row][new_col])
            {
                min_heap.push(Node{new_row, new_col, new_weight});
                visited[new_row][new_col] = new_weight;
            }
        }
    }

    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int t = 0; t < TC; t++)
    {
        int res = problem();
        printf("#%d %d\n", t + 1, res);
    }

    return 0;
}