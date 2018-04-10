#include<iostream>
using namespace std;

void dfs(int**, int*, int, int, int, int, int, int);
int MAX;
int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		MAX = 0;
		int N, K;
		int max = 0;
		scanf("%d", &N);
		scanf("%d", &K);

		int** map = new int*[N];
		int* visited = new int[N*N];
		for (int i = 0; i < N*N; i++)
			visited[i] = 0;
		for (int i = 0; i < N; i++)
			map[i] = new int[N];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int input;
				scanf("%d", &input);
				if (max < input)
					max = input;
				map[i][j] = input;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == max)
				{
					dfs(map, visited, i, j, K, N, 1, 1);
				}
			}
		}

		printf("#%d %d\n", t, MAX);
	}
	return 0;
}

void dfs(int** map, int* visited, int y, int x, int K, int N, int check, int length)
{
	//   printf("y : %d x : %d\n", y, x);
	if (check == 0)
	{
		int end = 0;         // 0�̸� ���� ����. 1�̸� ���� �ִ�.

		if ((y > 0) && (map[y][x] > map[y - 1][x]))
			end = 1;
		if ((x + 1 < N) && (map[y][x] > map[y][x + 1]))
			end = 1;
		if ((y + 1 < N) && (map[y][x] > map[y + 1][x]))
			end = 1;
		if ((x > 0) && (map[y][x] > map[y][x - 1]))
			end = 1;

		if (end == 0)
		{
			//         printf("Check 0 ��. length : %d\n", length);
			if (length > MAX)
				MAX = length;
			return;
		}
	}
	else if (check == 1)//&& ((map[y][x] <= map[y - 1][x] - K) || (map[y][x] <= map[y][x + 1] - K) || (map[y][x] <= map[y + 1][x] - K) || (map[y][x] <= map[y][x - 1] - K)))
	{
		int end = 0;
		if ((y > 0) && (map[y][x] > map[y - 1][x] - K) && (visited[N*(y - 1) + x] == 0))
		{
			//         printf("����1\n");
			end = 1;
		}
		if ((x + 1 < N) && (map[y][x] > map[y][x + 1] - K) && (visited[N*y + x + 1] == 0))
		{
			//         printf("����2\n");
			end = 1;
		}
		if ((y + 1 < N) && (map[y][x] > map[y + 1][x] - K) && (visited[N*(y + 1) + x] == 0))
		{
			//         printf("����3\n");
			end = 1;
		}
		if ((x > 0) && (map[y][x] > map[y][x - 1] - K) && (visited[N*y + x - 1] == 0))
		{
			//         printf("����4\n");
			end = 1;
		}
		if (end == 0)
		{
			//         printf("Check 1 ��. length : %d\n",length);
			if (length > MAX)
				MAX = length;
			return;
		}
	}

	visited[N*y + x] = 1;
	for (int a = K; a > 0; a--)
	{
		if ((y > 0) && (map[y][x] <= map[y - 1][x]) && (map[y][x] > (map[y - 1][x] - a)) && (check == 1) && (visited[N*(y - 1) + x] == 0))      // ��� ũ�ų� ������
		{
			//      printf("here minus ��\n");
			map[y - 1][x] -= a;
			dfs(map, visited, y - 1, x, a, N, 0, length + 1);
			map[y - 1][x] += a;
		}
		if ((x + 1 < N) && (map[y][x] <= map[y][x + 1]) && (map[y][x] > (map[y][x + 1] - a)) && (check == 1) && (visited[N*(y)+x + 1] == 0))      // ���� ũ�ų� ������
		{
			//      printf("here minus ��\n");
			map[y][x + 1] -= a;
			dfs(map, visited, y, x + 1, a, N, 0, length + 1);
			map[y][x + 1] += a;
		}
		if ((y + 1 < N) && (map[y][x] <= map[y + 1][x]) && (map[y][x] > (map[y + 1][x] - a)) && (check == 1) && (visited[N*(y + 1) + x] == 0))      // �ϴ� ũ�ų� ������
		{
			//      printf("here minus ��\n");
			map[y + 1][x] -= a;
			dfs(map, visited, y + 1, x, a, N, 0, length + 1);
			map[y + 1][x] += a;
		}
		if ((x > 0) && (map[y][x] <= map[y][x - 1]) && (map[y][x] > (map[y][x - 1] - a)) && (check == 1) && (visited[N*(y)+x - 1] == 0))      // ���� ũ�ų� ������
		{
			//      printf("here minus ��\n");
			map[y][x - 1] -= a;
			dfs(map, visited, y, x - 1, a, N, 0, length + 1);
			map[y][x - 1] += a;
		}
	}
	if ((y > 0) && (map[y][x] > map[y - 1][x]) && (visited[N*(y - 1) + x] == 0))      // ����� �� ���� ��
	{
		//      printf("here ��\n");
		dfs(map, visited, y - 1, x, K, N, check, length + 1);
	}
	if ((x + 1 < N) && (map[y][x] > map[y][x + 1]) && (visited[N*(y)+x + 1] == 0))      // ������ �� ���� ��
	{
		//      printf("here ��\n");
		dfs(map, visited, y, x + 1, K, N, check, length + 1);
	}
	if ((y + 1 < N) && (map[y][x] > map[y + 1][x]) && (visited[N*(y + 1) + x] == 0))      // ����� �� ���� ��
	{
		//      printf("here ��\n");
		dfs(map, visited, y + 1, x, K, N, check, length + 1);
	}
	if ((x > 0) && (map[y][x] > map[y][x - 1]) && (visited[N*(y)+x - 1] == 0))      // ����� �� ���� ��
	{
		//      printf("here ��\n");
		dfs(map, visited, y, x - 1, K, N, check, length + 1);
	}
	visited[N*y + x] = 0;
}