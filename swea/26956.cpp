#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node
{
	Node *prev;
	Node *next;
	int value;
};

void problem(int tc)
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	// first node
	int val;
	scanf("%d", &val);	
	Node start{ &start, &start, val };
	Node *temp = nullptr;

	// init beads
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &val);
		Node *node = new Node{ start.prev, &start, val };
		start.prev->next = node;
		start.prev = node;
	}

	// operates
	temp = &start;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < M; j++)
			temp = temp->next;
		Node *node = new Node{ temp->prev, temp, temp->prev->value + temp->value };
		temp->prev->next = node;
		temp->prev = node;
		temp = node;
	}

	// print
	temp = start.prev;
	printf("#%d", tc);
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", temp->value);
		temp = temp->prev;
		if (temp->next == &start)
			break;
	}
	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
		problem(t);
	return 0;
}