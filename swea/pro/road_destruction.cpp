#include <vector>
#include <unordered_map>
#include <limits>
#include <queue>

using namespace std;

struct Edge
{
    int id;
    int index;
    int start;
    int end;
    int time;
    bool valid;
};

struct Node
{
    int index;
    int time;
    bool operator<(const Node &other) const
    {
        return this->time > other.time;
    }
};

int N, K;
unordered_map<int, int> edge_dict;
vector<Edge> edges;
vector<vector<int>> graph;
vector<int> parents;
vector<int> min_path;

void init(int N, int K, int mId[], int sCity[], int eCity[], int mTime[])
{
    edge_dict.clear();
    graph.clear();

    ::N = N;
    ::K = K;
    graph.assign(N, vector<int>());
    parents.assign(N, -1);

    for (int i = 0; i < K; i++)
    {
        int index = edges.size();
        Edge new_edge = Edge{mId[i], index, sCity[i], eCity[i], mTime[i], true};
        edges.push_back(new_edge);
        edge_dict[mId[i]] = index;
        graph[sCity[i]].push_back(index);
    }

    return;
}

void add(int mId, int sCity, int eCity, int mTime)
{
    int index = edges.size();
    Edge edge = Edge{mId, index, sCity, eCity, mTime, true};
    edges.push_back(edge);
    edge_dict[mId] = index;
    graph[sCity].push_back(index);
    return;
}

void remove(int mId)
{
    int index = edge_dict[mId];
    edges[index].valid = false;
    return;
}

int dijkstra(int start, int end, int banned)
{
    // start: start point, end: end point, banned: destroyed raod
    const int MAX_VAL = numeric_limits<int>::max();
    vector<int> times(N, MAX_VAL);
    parents.assign(N, -1);
    priority_queue<Node> heap;
    
    heap.push(Node{start, 0});
    while (!heap.empty())
    {
        Node node = heap.top();
        heap.pop();

        if (node.index == end)
            break;

        if (node.time > times[node.index])
            continue;

        for (int edge_index : graph[node.index])
        {
            const Edge &edge = edges[edge_index];
            if (!edge.valid || edge.index == banned)
                continue;
            
            int new_time = times[edge.start] + edge.time;
            if (times[edge.end] > new_time)
            {
                times[edge.end] = new_time;
                heap.push(Node{edge.end, times[edge.end]});
                parents[edge.end] = edge.index;
            }
        }
    }

    if (parents[end] == -1)
        return -1;
    return times[end];
}

int calculate(int sCity, int eCity)
{
    // first dijkstra: finding shortest path
    int original_time =  dijkstra(sCity, eCity, -1);
    if (original_time == -1)
        return -1;

    // shortest path
    vector<int> path;
    int node_index = eCity;
    while (node_index != sCity)
    {
        int edge_index = parents[node_index];
        if (edge_index == -1)
            return -1;
        const Edge &parent_edge = edges[edge_index];
        path.push_back(edge_index);
        node_index = parent_edge.start;
    }

    int max_val = -1;
    // second dijkstra: finding a edge has most expensive bypass cost
    for (int &edge_index: path)
    {
        int bypass_time = dijkstra(sCity, eCity, edge_index);
        if (bypass_time == -1)
            return -1;
        max_val = max(max_val, bypass_time - original_time);
    }

    return max_val;
}
