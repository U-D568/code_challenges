#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BUNode
{
    int parent;
    int depth;
};

struct TDNode
{
    int left_child;
    int right_child;
};

struct Answer
{
    int node;
    int count;
};

Answer problem()
{
    int V, E, v1, v2;
    scanf("%d %d %d %d", &V, &E, &v1, &v2);
    vector<BUNode> bottom_up(V + 1);                // parent_id, depth
    vector<TDNode> top_down(V + 1, TDNode{-1, -1}); // left_child, right_child

    // initialize top-down tree
    for (int i = 0; i < V + 1; i++)
        bottom_up[i] = BUNode{i, -1};
    bottom_up[1].depth = 1;

    for (int e = 0; e < E; e++)
    {
        int parent, child;
        scanf("%d %d", &parent, &child);
        bottom_up[child].parent = parent;

        if (top_down[parent].left_child == -1)
            top_down[parent].left_child = child;
        else if (top_down[parent].right_child == -1)
            top_down[parent].right_child = child;
    }

    // calculates depths of nodes
    queue<int> depth_queue;
    depth_queue.push(1);
    while (!depth_queue.empty())
    {
        int parent_node = depth_queue.front();
        depth_queue.pop();

        int left_node = top_down[parent_node].left_child;
        int right_node = top_down[parent_node].right_child;
        if (left_node != -1)
        {
            bottom_up[left_node].depth = bottom_up[parent_node].depth + 1;
            depth_queue.push(left_node);
        }

        if (right_node != -1)
        {
            bottom_up[right_node].depth = bottom_up[parent_node].depth + 1;
            depth_queue.push(right_node);
        }
    }

    // find closest co-parent
    while (v1 != v2)
    {
        if (bottom_up[v1].depth > bottom_up[v2].depth)
            v1 = bottom_up[v1].parent;
        else
            v2 = bottom_up[v2].parent;
    }

    // counts children of co-parent
    int cnt = 0;
    queue<int> subtree_queue;
    subtree_queue.push(v1);
    while (!subtree_queue.empty())
    {
        int parent = subtree_queue.front();
        subtree_queue.pop();
        cnt++;

        int left_child = top_down[parent].left_child;
        int right_child = top_down[parent].right_child;
        if (left_child != -1)
            subtree_queue.push(left_child);
        if (right_child != -1)
            subtree_queue.push(right_child);
    }

    return Answer{v1, cnt};
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        Answer res = problem();
        printf("#%d %d %d\n", t + 1, res.node, res.count);
    }
}