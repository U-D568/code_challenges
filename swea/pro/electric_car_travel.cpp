#define MAX_CITIES 500
#define MAX_ROADS 4000
#define MAX_BATTERY 300

#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <chrono>

using namespace std;

struct Node
{
	int id; // same as index
	int charge;
};

struct Edge
{
	int index;
	int id;
	int time;
	int power;
	int start;
	int end;
	bool valid = true;
};

struct Virus
{
	int node_id;
	int time;

	bool operator < (const Virus &other) const
	{
		return this->time > other.time;
	}
};

int N;
vector<Node> nodes;
vector<Edge> edges;
unordered_map<int, int> edge_ids;
vector<vector<int>> graph;


void init(int N, int mCharge[], int K, int mId[], int sCity[], int eCity[], int mTime[], int mPower[])
{
	::N = N;
	nodes.assign(N, Node{});
	edges.assign(K, Edge{});
	graph.assign(N, vector<int>());
	edge_ids.clear();

	for (int i = 0; i < N; i++)
	{
		nodes[i].id = i;
		nodes[i].charge = mCharge[i];
	}

	for (int i = 0; i < K; i++)
	{
		edges[i].index = i;
		edges[i].id = mId[i];
		edges[i].time = mTime[i];
		edges[i].power = mPower[i];
		edges[i].start = sCity[i];
		edges[i].end = eCity[i];
		edges[i].valid = true;

		edge_ids[mId[i]] = i;
		graph[sCity[i]].push_back(i);
	}

	return;
}

void add(int mId, int sCity, int eCity, int mTime, int mPower)
{
	int index = edges.size();
	Edge edge = Edge{ index , mId, mTime, mPower, sCity, eCity };
	edges.push_back(edge);
	edge_ids[mId] = index;
	graph[sCity].push_back(index);

	return;
}

void remove(int mId)
{
	int i = edge_ids[mId];
	Edge &edge = edges[i];
	edge.valid = false;

	return;
}

struct Travel
{
	int node_id;
	int time;
	int power;
	bool operator < (const Travel &other) const
	{
		if (this->time == other.time)
			return this->power < other.power;
		return this->time > other.time;
	}
};

int dp[MAX_CITIES][MAX_BATTERY + 1];
int virus_times[MAX_CITIES];


void virus_dijkstra(int target, vector<Virus> &init_nodes)
{
	priority_queue<Virus> min_heap;
	for (const Virus &path : init_nodes)
		min_heap.push(path);

	while (!min_heap.empty())
	{
		Virus path = min_heap.top();
		min_heap.pop();

		if (virus_times[path.node_id] < path.time)
			continue;

		for (int edge_idx : graph[path.node_id])
		{
			const Edge &next_edge = edges[edge_idx];
			if (!next_edge.valid)
				continue;
			int next_weight = next_edge.time + path.time;
			int next_node = next_edge.end;
			if (next_weight >= virus_times[next_node])
				continue;
			virus_times[next_node] = next_weight;
			min_heap.push(Virus{ next_node, next_weight });
		}
	}

	return;
}

int cost(int B, int sCity, int eCity, int M, int mCity[], int mTime[])
{
	fill(&dp[0][0], &dp[0][0] + MAX_CITIES * (MAX_BATTERY + 1), numeric_limits<int>::max());
	fill(&virus_times[0], &virus_times[0] + MAX_CITIES, numeric_limits<int>::max());
	vector<Virus> virus_init(M);
	for (int i = 0; i < M; i++)
	{
		virus_init[i].node_id = mCity[i];
		virus_init[i].time = mTime[i];
		virus_times[mCity[i]] = mTime[i];
	}

	// calculates virus times
	virus_dijkstra(-1, virus_init);

	priority_queue<Travel> min_heap;
	dp[sCity][B] = 0;
	min_heap.push({ sCity, 0, B });
	if (virus_times[sCity] == 0)
		return -1;

	while (!min_heap.empty())
	{
		Travel travel = min_heap.top();
		min_heap.pop();

		if (travel.node_id == eCity)
			return travel.time;

		if (travel.time > dp[travel.node_id][travel.power])
			continue;

		if (travel.power < B && travel.time + 1 < virus_times[travel.node_id]) // charging
		{
			int next_power = travel.power + nodes[travel.node_id].charge;
			int next_time = travel.time + 1;
			next_power = min(B, next_power);

			bool is_max = true; // current power is fastest 
			for (int p = next_power; p <= B; p++)
			{
				if (dp[travel.node_id][p] <= next_time)
				{
					is_max = false;
					break;
				}
			}

			if (is_max)
			{
				dp[travel.node_id][next_power] = next_time;
				min_heap.push(Travel{ travel.node_id, next_time, next_power });
			}
		}

		for (int edge_id : graph[travel.node_id])
		{
			const Edge &next_edge = edges[edge_id];
			if (!next_edge.valid)
				continue;
			int next_node = next_edge.end;

			int next_power = travel.power - next_edge.power;
			if (next_power < 0)
				continue;

			int next_time = travel.time + next_edge.time;
			if (next_time >= virus_times[next_node])
				continue;

			if (dp[next_node][next_power] <= next_time)
				continue;
			dp[next_node][next_power] = next_time;

			min_heap.push(Travel{ next_node, next_time, next_power });
		}
	}

	return -1;
}