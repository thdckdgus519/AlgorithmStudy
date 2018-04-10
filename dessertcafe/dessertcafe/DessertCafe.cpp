#include<iostream>
using namespace std;

int result = -1;
int visited[101];
void dfs(int**, int, int, int, int, int, int, int);

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int N;
		scanf("%d", &N);

		result = -1;

		int** cafe = new int*[N];

		for (int i = 0; i < 101; i++)
			visited[i] = 0;

		for (int i = 0; i < N; i++)
		{
			cafe[i] = new int[N];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a;
				scanf("%d", &a);
				cafe[i][j] = a;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((j != 0) && (j != N - 1) && (i != N - 2) && (i != N - 1))
				{
					//                  cout << "i : " << i << " j : " << j << endl;
					dfs(cafe, i, j, i, j, 0, 0, N);
				}
			}
		}

		printf("#%d %d\n", t, result);
	}

	return 0;
}

void dfs(int** cafe, int y, int x, int fy, int fx, int mode, int n, int N)
{
	if ((n >= 4) && (y == fy) && (x == fx))
	{
		if (result < n)
			result = n;
		return;
	}

	//  cout << "n : " << n << " mode : " << mode << endl;
	//  cout << "y : " << y << " x : " << x <<" cafe : " << cafe[y][x] << endl;
	//  cout << "=======================" << endl;
	visited[cafe[y][x]] = 1;

	if (mode == 0) //¿À¾Æ
	{
		if ((y + 1 < N) && (x + 1 < N) && (visited[cafe[y + 1][x + 1]] == 0))
		{
			dfs(cafe, y + 1, x + 1, fy, fx, 0, n + 1, N);
		}
		if ((y + 1 < N) && (x > 0) && (visited[cafe[y + 1][x - 1]] == 0))
		{
			dfs(cafe, y + 1, x - 1, fy, fx, 1, n + 1, N);
		}
	}
	else if (mode == 1) // ¿Þ¾Æ
	{
		if ((y + 1 < N) && (x > 0) && (visited[cafe[y + 1][x - 1]] == 0))
		{
			dfs(cafe, y + 1, x - 1, fy, fx, 1, n + 1, N);
		}
		if ((y > 0) && (x > 0) && (visited[cafe[y - 1][x - 1]] == 0))
		{
			dfs(cafe, y - 1, x - 1, fy, fx, 2, n + 1, N);
		}
	}
	else if (mode == 2) // ¿ÞÀ§
	{
		if ((y > 0) && (x > 0) && (visited[cafe[y - 1][x - 1]] == 0))
		{
			dfs(cafe, y - 1, x - 1, fy, fx, 2, n + 1, N);
		}
		if ((y > 0) && (x + 1 < N) && (visited[cafe[y - 1][x + 1]] == 0))
		{
			dfs(cafe, y - 1, x + 1, fy, fx, 3, n + 1, N);
		}
		if ((y > 0) && (x + 1 < N) && (y - 1 == fy) && (x + 1 == fx))
		{
			dfs(cafe, y - 1, x + 1, fy, fx, 3, n + 1, N);
		}
	}
	else if (mode == 3)// ¿ÀÀ§
	{
		if ((y > 0) && (x + 1 < N) && (visited[cafe[y - 1][x + 1]] == 0))
		{
			dfs(cafe, y - 1, x + 1, fy, fx, 3, n + 1, N);
		}
		if ((y > 0) && (x + 1 < N) && (y - 1 == fy) && (x + 1 == fx))
		{
			dfs(cafe, y - 1, x + 1, fy, fx, 3, n + 1, N);
		}
	}

	visited[cafe[y][x]] = 0;
}