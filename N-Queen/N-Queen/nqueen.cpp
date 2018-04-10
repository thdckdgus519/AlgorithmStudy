#include<iostream>
using namespace std;

int num;
int check(int **, int);
void dfs(int, int, int**, int, int);
void plusC(int**, int, int, int);
void deleteC(int**, int, int, int);

int main(void)
{
	int T;
	num = 0;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		int N;
		scanf("%d", &N);
		
		int** chess = new int*[N];
		for (int i = 0; i < N; i++)
		{
			chess[i] = new int[N];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				chess[i][j] = 0;
		}

		for (int k = 0; k < N; k++)
		{
			for (int j = 0; j < N; j++)
			{
				dfs(j, k, chess,1,N);
			}
		}
		cout << "#" << i << " " << num << endl;
		num = 0;
	}

	return 0;
}

void dfs(int x,int y,int** chess, int n, int N)
{
	if (n == N)
	{
		if (n == N)
		{
			num++;
		}
		return;
	}

	if (check(chess, N) == 1)
	{
		cout << " here " << endl;

		return;
	}


	cout << " ======================= " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << chess[i][j] << " ";
		cout << endl;
	}

	cout << "check : " << check(chess, N) << " n : " << n << " N : " << N << " x : " << x << " y : " << y << endl;

	plusC(chess, x, y, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chess[i][j] == 0)
			{
				dfs(j, i, chess, n + 1, N);
			}
		}
	}

	deleteC(chess, x, y, N);
}

int check(int** chess,int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chess[i][j] == 0)
				result = 0;
		}
	}

	return result;
}

void plusC(int** chess, int x, int y, int N)
{
	
	chess[y][x] += 1;
	for (int i = x; i < N; i++)
	{
		if (i == x)
			continue;
		chess[y][i] += 1;
	}
	for (int i = x; i >= 0; i--)
	{
		if (i == x)
			continue;
		chess[y][i] += 1;
	}
	for (int i = y; i < N; i++)
	{
		if (i == y)
			continue;
		chess[i][x] += 1;
	}
	for (int i = y; i >= 0; i--)
	{
		if (i == y)
			continue;
		chess[i][x] += 1;
	}
	int i, j;

	i = x;
	j = y;
	while (i < N && j < N)
	{
		if (i == x && j == y)
		{
			i++;
			j++;
			continue;
		}
		chess[j][i] += 1;
		i++;
		j++;
	}

	i = x;
	j = y;
	while (i < N && j >= 0)
	{
		if (i == x && j == y)
		{
			i++;
			j--;
			continue;
		}
		chess[j][i] += 1;
		i++;
		j--;
	}

	i = x;
	j = y;
	while (i >= 0 && j >= 0)
	{
		if (i == x && j == y)
		{
			i--;
			j--;
			continue;
		}
		chess[j][i] += 1;
		i--;
		j--;
	}

	i = x;
	j = y;
	while (i >= 0 && j < N)
	{
		if (i == x && j == y)
		{
			i--;
			j++;
			continue;
		}
		chess[j][i] += 1;
		i--;
		j++;
	}
}
void deleteC(int** chess, int x, int y, int N)
{

	chess[y][x] -= 1;
	for (int i = x; i < N; i++)
	{
		if (i == x)
			continue;
		chess[y][i] -= 1;
	}
	for (int i = x; i >= 0; i--)
	{
		if (i == x)
			continue;
		chess[y][i] -= 1;
	}
	for (int i = y; i < N; i++)
	{
		if (i == y)
			continue;
		chess[i][x] -= 1;
	}
	for (int i = y; i >= 0; i--)
	{
		if (i == y)
			continue;
		chess[i][x] -= 1;
	}
	int i, j;

	i = x;
	j = y;
	while (i < N && j < N)
	{
		if (i == x && j == y)
		{
			i++;
			j++;
			continue;
		}
		chess[j][i] -= 1;
		i++;
		j++;
	}

	i = x;
	j = y;
	while (i < N && j >= 0)
	{
		if (i == x && j == y)
		{
			i++;
			j--;
			continue;
		}
		chess[j][i] -= 1;
		i++;
		j--;
	}

	i = x;
	j = y;
	while (i >= 0 && j >= 0)
	{
		if (i == x && j == y)
		{
			i--;
			j--;
			continue;
		}
		chess[j][i] -= 1;
		i--;
		j--;
	}

	i = x;
	j = y;
	while (i >= 0 && j < N)
	{
		if (i == x && j == y)
		{
			i--;
			j++;
			continue;
		}
		chess[j][i] -= 1;
		i--;
		j++;
	}
}