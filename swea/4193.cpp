#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct action
{
	int step;
	int row;
	int col;
};

bool is_valid(int row, int col, int N)
{
	return !(row < 0 || row >= N || col < 0 || col >= N);
}

int problem()
{
	int N;
	scanf("%d", &N);

	vector<vector<int>> field(N, vector<int>(N, 0));
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	queue<action> action_queue;

	vector<int> d_row = { -1, 1, 0, 0 };
	vector<int> d_col = { 0, 0, -1, 1 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &field[i][j]);
			if (field[i][j] == 1)
				visited[i][j] = true;
		}
	}

	int st_row, st_col;
	int end_row, end_col;
	scanf("%d %d", &st_row, &st_col);
	scanf("%d %d", &end_row, &end_col);

	action init = { 0, st_row, st_col};
	action_queue.push(init);
	while (!action_queue.empty())
	{
		action current = action_queue.front();
		action_queue.pop();
		visited[current.row][current.col] = true;

		bool is_active = current.step % 3 != 2; // tornado

		// finish
		if (current.row == end_row && current.col == end_col)
			return current.step;

		// searches new path
		for (int i = 0; i < 4; i++)
		{
			int n_row = current.row + d_row[i];
			int n_col = current.col + d_col[i];

			if (!is_valid(n_row, n_col, N))
				continue;
			if (visited[n_row][n_col])
				continue;
			if (field[n_row][n_col] == 2 && is_active)
			{
				n_row = current.row;
				n_col = current.col;
			}

			action next = { current.step + 1, n_row, n_col };
			action_queue.push(next);
		}
	}

	return -1;
}


int main()
{
	int TC;
	scanf("%d", &TC);

	for (int tc = 0; tc < TC; tc++)
	{
		int cnt = problem();
		printf("#%d %d\n", tc + 1, cnt);
	}

	return 0;
}