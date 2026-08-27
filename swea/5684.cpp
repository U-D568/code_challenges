#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
 
using namespace std;
 
struct Edge
{
    int from;
    int to;
    int weight;
};
 
struct Node
{
    int id;
    int weight;
    bool operator < (const Node &other) const {
        return this->weight > other.weight;
    }
};
 
int min_val = INT_MAX;
 
 
int problem()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<Edge>> graph(N + 1, vector<Edge>());
    vector<vector<Edge>> reverse_graph(N + 1, vector<Edge>());
 
    const int MAX_VAL = INT_MAX / 2;
    min_val = MAX_VAL;
    for (int m = 0; m < M; m++)
    {
        int st, ed, w;
        scanf("%d %d %d", &st, &ed, &w);
        Edge edge = Edge{ st, ed, w };
        graph[st].push_back(edge);
        reverse_graph[ed].push_back(edge);
    }
 
    for (int i = 1; i <= N; i++)
    {
        priority_queue<Node> min_heap;
        vector<int> dist(N + 1, MAX_VAL); // accumulated distance at each node
         
        // dijkstra
        min_heap.push(Node{ i, 0 });
        dist[i] = 0;
        while (!min_heap.empty())
        {
            Node node = min_heap.top();
            min_heap.pop();
 
            for (Edge edge : graph[node.id])
            {
                int new_weight = dist[edge.from] + edge.weight;
                if (dist[edge.to] <= new_weight)
                    continue;
                dist[edge.to] = new_weight;
                min_heap.push(Node{ edge.to, new_weight });
            }
        }
 
        // checks cyles
        for (Edge e : reverse_graph[i])
        {
            if (dist[e.from] == MAX_VAL)
                continue;
            min_val = min(min_val, dist[e.from] + e.weight);
        }
    }
 
    return min_val;
}
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int t = 1; t <= T; t++)
        printf("#%d %d\n", t, problem());
 
    return 0;
}