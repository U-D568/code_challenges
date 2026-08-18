#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node
{
	int id;
	int position;
	int prev_id;
	int next_id;
	int distance;
	bool is_active;

	bool operator<(const Node &other) const
	{
		if (this->distance == other.distance)
			return this->position > other.position;
		else
			return this->distance < other.distance;
	}
};

int N, M;
vector<Node> node_list;
priority_queue<Node, vector<Node>, less<Node>> node_heap;
int first_id = 1;
int last_id = -1;

void add_light()
{
	Node node;
	while (!node_heap.empty())
	{
		node = node_heap.top();
		node_heap.pop();
		if (!node_list[node.id].is_active)
			continue;
		if (node_list[node.id].prev_id == -1)
			continue;
		if (node_list[node.id].prev_id != node.prev_id)
			continue;
		break;
	}

	node = node_list[node.id];
	int prev_pos = node_list[node.prev_id].position;
	int new_pos = prev_pos + (node.position - prev_pos + 1) / 2;
	Node new_node = {
		(int)node_list.size(),
		new_pos,
		node.prev_id,
		node.id,
		new_pos - prev_pos,
		true };
	node_list[node.prev_id].next_id = new_node.id;
	node_list[node.id].distance = node.position - new_pos;
	node_list[node.id].prev_id = new_node.id;

	node_list.push_back(new_node);
	node_heap.push(new_node);
	node_heap.push(node_list[new_node.next_id]);
}

void remove_light(int id)
{
	Node &target = node_list[id];
	target.is_active = false;
	int prev_id = target.prev_id;
	int next_id = target.next_id;
	if (prev_id != -1)
	{
		if (next_id == -1)
			last_id = prev_id;
		node_list[prev_id].next_id = next_id;
	}

	if (next_id != -1)
	{
		if (prev_id == -1)
		{
			node_list[next_id].distance = node_list[next_id].position - 1;
			first_id = next_id;
		}
		else
			node_list[next_id].distance = node_list[next_id].position - node_list[prev_id].position;
		node_list[next_id].prev_id = prev_id;

		node_heap.push(node_list[next_id]);
	}
}

void init_ligts()
{
	scanf("%d", &N);
	scanf("%d", &M);
	node_list.push_back(Node{ -1, -1, -1, -1, -1, false });

	for (int i = 1; i <= M; i++)
	{
		int position, left_dist = -1;
		scanf("%d", &position);
		if (i == 1)
			left_dist = position - 1;
		else
			left_dist = position - node_list[i - 1].position;
		Node new_node = Node{ i, position, (i == 1) ? -1 : i - 1, -1, left_dist, true };

		if (i > 1)
			node_list[i - 1].next_id = i;

		node_list.push_back(new_node);
		node_heap.push(new_node);
	}

	last_id = node_list[(int)node_list.size() - 1].id;
}

int cal_efficiency()
{
	int max_val = max(node_list[first_id].position - 1, N - node_list[last_id].position);
	max_val *= 2;
	int cur_id = first_id;
	Node node;
	while (!node_heap.empty())
	{
		node = node_heap.top();

		if (!node_list[node.id].is_active)
		{
			node_heap.pop();
			continue;
		}

		if (node_list[node.id].prev_id == -1)
		{
			node_heap.pop();
			continue;
		}

		if (node_list[node.id].prev_id != node.prev_id)
		{
			node_heap.pop();
			continue;
		}

		max_val = max(max_val, node.distance);
		break;
	}

	return max_val;
}

int main()
{
	int Q;
	scanf("%d", &Q);

	for (int i = 0; i < Q; i++)
	{
		int query, value;
		scanf("%d", &query);
		switch (query)
		{
		case 100:
			init_ligts();
			break;
		case 200:
			add_light();
			break;
		case 300:
			scanf("%d", &value);
			remove_light(value);
			break;
		case 400:
			value = cal_efficiency();
			printf("%d\n", value);
			break;
		}
	}

	return 0;
}