#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int problem()
{
	int N, M;
	int revenue = 0;
	scanf("%d %d", &N, &M);

	vector<int> slot_prices(N);
	vector<int> car_weights(M + 1);

	unordered_map<int, int> hashmap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for (int i = 0; i < N; i++)
		min_heap.push(i);

	queue<int> waiting_queue;

	for (int i = 0; i < N; i++)
		scanf("%d", &slot_prices[i]);

	for (int i = 1; i <= M; i++)
		scanf("%d", &car_weights[i]);

	for (int i = 0; i < 2 * M; i++)
	{
		int car_id;
		scanf("%d", &car_id);

		if (car_id < 0)
		{
			int slot_id = hashmap.at(-car_id);
			hashmap.erase(car_id);
			min_heap.push(slot_id);
		}
		else
		{
			waiting_queue.push(car_id);
		}

		while (!min_heap.empty())
		{
			if (waiting_queue.empty())
				break;

			int car_id = waiting_queue.front();
			waiting_queue.pop();

			int slot_id = min_heap.top();
			min_heap.pop();

			hashmap[car_id] = slot_id;

			revenue += car_weights[car_id] * slot_prices[slot_id];
		}
	}

	return revenue;
}

int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);

	for (int t = 0; t < TC; t++)
	{
		int revenue = problem();
		printf("#%d %d\n", t + 1, revenue);
	}

	return 0;
}