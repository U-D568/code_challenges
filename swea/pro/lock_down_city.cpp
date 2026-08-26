#include <vector>
#include <limits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>

#define MAX_M 4
#define MAX_N 100

using namespace std;

struct Node
{
	int row;
	int col;
	int step;
	unsigned int cur_grade;
	unsigned int path_grade;

	bool operator < (const Node &other) const
	{
		if (this->path_grade == other.path_grade)
			return this->step > other.step;
		return this->path_grade < other.path_grade;
	}
};

char ret[MAX_M];
int N, M;
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

vector<vector<unsigned int>> field;

unsigned int encode(const char str[MAX_M])
{
	unsigned int val = 0;
	int i = 0;

	while (i < MAX_M && str[i] != '\0')
	{
		val = (val << 8) | str[i];
		i++;
	}

	while (i < MAX_M)
	{
		val <<= 8;
		i++;
	}

	return val;
}


void decode(unsigned int val, char out[MAX_M])
{
	for (int i = MAX_M - 1; i >= 0; i--)
	{
		out[i] = val & 0xFF;
		val >>= 8;
	}
}

bool is_valid(int row, int col)
{
	return !(row < 0 || row >= N || col < 0 || col >= N);
}

void init(int N, int M, char mGrade[][MAX_N][MAX_M])
{
	::N = N;
	::M = M;
	field.assign(N, vector<unsigned int>(N));
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			field[row][col] = encode(mGrade[row][col]);
	}
}

void change(int mRow, int mCol, int mDir, int mLength, char mGrade[MAX_M])
{
	switch (mDir)
	{
	case 0:
		for (int i = 0; i < mLength; i++)
			field[mRow + i][mCol] = encode(mGrade);
		break;
	case 1:
		for (int i = 0; i < mLength; i++)
			field[mRow][mCol + i] = encode(mGrade);
		break;
	}
}


char* calculate(int L, int sRow, int sCol, int eRow, int eCol)
{
	vector<vector<unsigned int>> grades(N, vector<unsigned int>(N, 0x0));
	vector<vector<int>> steps(N, vector<int>(N, numeric_limits<int>::max()));
	priority_queue<Node> priorities;

	priorities.push(Node{ sRow, sCol, 0, 0xFFFFFFFF, 0xFFFFFFFF });
	while (!priorities.empty())
	{
		Node node = priorities.top();
		priorities.pop();

		if (grades[node.row][node.col] > node.path_grade)
			continue;

		if (node.step >= L)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nr = dr[i] + node.row; // new row
			int nc = dc[i] + node.col; // new column
			if (!is_valid(nr, nc))
				continue;

			// checks is reached to destination
			if (nr == eRow && nc == eCol)
			{
				unsigned int result = min(field[nr][nc], node.path_grade);
				decode(result, ret);
				return ret;
			}

			// manhattan pruning
			int remain_steps = L - node.step - 1;
			int distance = abs(eRow - nr) + abs(eCol - nc);
			if (distance > remain_steps)
				continue;

			// dijkstra
			unsigned int cur_grade = field[nr][nc];
			unsigned int path_grade = min(cur_grade, node.path_grade);
			if (grades[nr][nc] > path_grade)
				continue;
			else if (grades[nr][nc] == path_grade && steps[nr][nc] <= node.step + 1)
				continue;
			grades[nr][nc] = path_grade;
			steps[nr][nc] = node.step + 1;
			priorities.push(Node{ nr, nc, node.step + 1, cur_grade, path_grade });
		}
	}

	return ret;
}