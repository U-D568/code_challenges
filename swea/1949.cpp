#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int global_max = -1;

bool is_valid(int row, int col, int N)
{
	return !(row < 0 || col < 0 || row >= N || col >= N);
}

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int row, int col, int max_dig, int depth)
{
	int cur_height = map[row][col];

	visited[row][col] = true;

	for (int dir = 0; dir < 4; dir++) // direction: up, down, left, right
	{
		int new_row = row + dr[dir];
		int new_col = col + dc[dir];

		if (!(is_valid(new_row, new_col, map.size())))
			continue;
		if (visited[new_row][new_col])
			continue;

		int next_height = map[new_row][new_col];
		if (cur_height <= next_height)
		{
			for (int dig = 1; dig <= max_dig; dig++)
			{
				if (next_height - dig < cur_height)
				{
					map[new_row][new_col] -= dig;
					dfs(map, visited, new_row, new_col, 0, depth + 1);
					map[new_row][new_col] += dig;
				}
			}
		}
		else
			dfs(map, visited, new_row, new_col, max_dig, depth + 1);
	}

	visited[row][col] = false;

	global_max = max(global_max, depth);
}

int problem()
{
	int N, K;
	int max_val = -1;
	scanf("%d %d", &N, &K);
	vector<vector<int>> map(N, vector<int>(N));
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	vector<pair<int, int>> start_points;

	// initialize field
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int val;
			scanf("%d", &val);
			map[r][c] = val;
			max_val = max(max_val, val);
		}
	}

	// find toppest locations
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (map[r][c] == max_val)
				start_points.push_back({ r, c });
		}
	}

	for (pair<int, int> st : start_points)
		dfs(map, visited, st.first, st.second, K, 1);

	return global_max;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);

	for (int t = 0; t < TC; t++)
	{
		global_max = -1;
		int result = problem();
		printf("#%d %d\n", t + 1, result);
	}

	return 0;
}