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
		int end = 0;         // 0이면 갈데 없음. 1이면 갈데 있다.

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
			//         printf("Check 0 끝. length : %d\n", length);
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
			//         printf("오잉1\n");
			end = 1;
		}
		if ((x + 1 < N) && (map[y][x] > map[y][x + 1] - K) && (visited[N*y + x + 1] == 0))
		{
			//         printf("오잉2\n");
			end = 1;
		}
		if ((y + 1 < N) && (map[y][x] > map[y + 1][x] - K) && (visited[N*(y + 1) + x] == 0))
		{
			//         printf("오잉3\n");
			end = 1;
		}
		if ((x > 0) && (map[y][x] > map[y][x - 1] - K) && (visited[N*y + x - 1] == 0))
		{
			//         printf("오잉4\n");
			end = 1;
		}
		if (end == 0)
		{
			//         printf("Check 1 끝. length : %d\n",length);
			if (length > MAX)
				MAX = length;
			return;
		}
	}

	visited[N*y + x] = 1;
	for (int a = K; a > 0; a--)
	{
		if ((y > 0) && (map[y][x] <= map[y - 1][x]) && (map[y][x] > (map[y - 1][x] - a)) && (check == 1) && (visited[N*(y - 1) + x] == 0))      // 상단 크거나 같을때
		{
			//      printf("here minus 북\n");
			map[y - 1][x] -= a;
			dfs(map, visited, y - 1, x, a, N, 0, length + 1);
			map[y - 1][x] += a;
		}
		if ((x + 1 < N) && (map[y][x] <= map[y][x + 1]) && (map[y][x] > (map[y][x + 1] - a)) && (check == 1) && (visited[N*(y)+x + 1] == 0))      // 우측 크거나 같을때
		{
			//      printf("here minus 동\n");
			map[y][x + 1] -= a;
			dfs(map, visited, y, x + 1, a, N, 0, length + 1);
			map[y][x + 1] += a;
		}
		if ((y + 1 < N) && (map[y][x] <= map[y + 1][x]) && (map[y][x] > (map[y + 1][x] - a)) && (check == 1) && (visited[N*(y + 1) + x] == 0))      // 하단 크거나 같을때
		{
			//      printf("here minus 남\n");
			map[y + 1][x] -= a;
			dfs(map, visited, y + 1, x, a, N, 0, length + 1);
			map[y + 1][x] += a;
		}
		if ((x > 0) && (map[y][x] <= map[y][x - 1]) && (map[y][x] > (map[y][x - 1] - a)) && (check == 1) && (visited[N*(y)+x - 1] == 0))      // 좌측 크거나 같을때
		{
			//      printf("here minus 서\n");
			map[y][x - 1] -= a;
			dfs(map, visited, y, x - 1, a, N, 0, length + 1);
			map[y][x - 1] += a;
		}
	}
	if ((y > 0) && (map[y][x] > map[y - 1][x]) && (visited[N*(y - 1) + x] == 0))      // 상단이 더 작을 때
	{
		//      printf("here 북\n");
		dfs(map, visited, y - 1, x, K, N, check, length + 1);
	}
	if ((x + 1 < N) && (map[y][x] > map[y][x + 1]) && (visited[N*(y)+x + 1] == 0))      // 우측이 더 작을 때
	{
		//      printf("here 동\n");
		dfs(map, visited, y, x + 1, K, N, check, length + 1);
	}
	if ((y + 1 < N) && (map[y][x] > map[y + 1][x]) && (visited[N*(y + 1) + x] == 0))      // 상단이 더 작을 때
	{
		//      printf("here 남\n");
		dfs(map, visited, y + 1, x, K, N, check, length + 1);
	}
	if ((x > 0) && (map[y][x] > map[y][x - 1]) && (visited[N*(y)+x - 1] == 0))      // 상단이 더 작을 때
	{
		//      printf("here 서\n");
		dfs(map, visited, y, x - 1, K, N, check, length + 1);
	}
	visited[N*y + x] = 0;
}