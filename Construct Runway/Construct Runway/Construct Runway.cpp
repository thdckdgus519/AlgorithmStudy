#include<iostream>
using namespace std;

int checkB(int** land, int* vistied, int y, int x, int num, int N);
int checkS(int** land, int* visited, int y, int x, int num, int N);
int checkBY(int** land, int* visited, int y, int x, int num, int N);
int checkSY(int** land, int* visited, int y, int x, int num, int N);

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int N, X;
		int total = 0;
		scanf("%d", &N);
		scanf("%d", &X);
		
		int** land = new int*[N];
		for (int i = 0; i < N; i++)
			land[i] = new int[N];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int input;
				scanf("%d", &input);
				land[i][j] = input;
			}
		}

		for (int i = 0; i < N; i++)
		{
//			printf("\ni : %d\n", i);
			int* visited = new int[N];
			for (int j = 0; j < N; j++)
			{
//				printf("j : %d ", j);
				if (j == 0)
				{
					int temp = land[i][j] - land[i][j + 1];
					if ((temp != 1) && (temp != 0))
					{
						break;
					}
					else if (temp == 1)
					{
						int c = checkB(land, visited, i, j, X, N);
						if (c == 0)
						{
							break;
						}
					}
				}
				else if (j == N-1)
					total++;
				else			// 3가지 경우 다음꺼랑 같다. 작다. 크다. 그 전에 안되는거부터 컷.
				{
					int temp = land[i][j] - land[i][j + 1];
					if ((temp != -1) && (temp != 0) && (temp != 1))
					{
						break;
					}
					if (temp == 1)
					{
						int c = checkB(land, visited, i, j, X, N);
						if (c == 0)
						{
							break;
						}
					}

					else if (temp == -1)
					{
						int c = checkS(land, visited, i, j, X, N);
						if (c == 0)
						{
							break;
						}
					}

					else if (temp == 0)
						continue;

				}
			}
		}

		for (int j = 0; j < N; j++)
		{
//			printf("\nj : %d\n", j);
			int* visited = new int[N];
			for (int i = 0; i < N; i++)
			{
//				printf("i : %d ", i);
				if (i == 0)
				{
					int temp = land[i][j] - land[i+1][j];
					if ((temp != 1) && (temp != 0))
					{
						break;
					}
					else if (temp == 1)
					{
						int c = checkBY(land, visited, i, j, X, N);
						if (c == 0)
						{
							break;
						}
					}
				}
				else if (i == N - 1)
					total++;
				else			// 3가지 경우 다음꺼랑 같다. 작다. 크다. 그 전에 안되는거부터 컷.
				{
					int temp = land[i][j] - land[i+1][j];
					if ((temp != -1) && (temp != 0) && (temp != 1))
					{
						break;
					}
					if (temp == 1)
					{
						int c = checkBY(land, visited, i, j, X, N);
						if (c == 0)
						{
							break;
						}
					}

					else if (temp == -1)
					{
						int c = checkSY(land, visited, i, j, X, N);
						if (c == 0)
						{
							break;
						}
					}

					else if (temp == 0)
						continue;

				}
			}
		}
		printf("#%d %d\n",t,total);


	}



	return 0;
} 

int checkS(int** land, int* visited, int y, int x, int num, int N)
{
	int total = 1;

	for (int i = 1; i < num; i++)
	{
		if (((x - i) < 0) || (visited[x - i] == 1))
			break;
		if (land[y][x] == land[y][x - i])
			total++;
	}
	if (total == num)
		return 1;
	else
		return 0;
}

int checkB(int** land, int* visited, int y, int x, int num, int N)
{
	int total = 1;

	for (int i = 1; i < num; i++)
	{
		if ( (x + 1 + i) >= N)
			break;
		if (land[y][x + 1] == land[y][(x + 1) + i])
		{
			visited[x + 1] = 1;
			visited[x + 1 + i] = 1;
			total++;
		}
	}

	if (total == num)
		return 1;
	else
		return 0;			// 1이면 Pass 0이면 Fail
}

int checkSY(int** land, int* visited, int y, int x, int num, int N)
{
	int total = 1;

	for (int i = 1; i < num; i++)
	{
		if ( ((y - i) < 0) || (visited[y - i] == 1) )
			break;
		if (land[y][x] == land[y - i][x])
			total++;
	}
	if (total == num)
		return 1;
	else
		return 0;
}

int checkBY(int** land, int* visited, int y, int x, int num, int N)
{
	int total = 1;

	for (int i = 1; i < num; i++)
	{
		if ( (y + 1 + i) >= N)
			break;
		if (land[y + 1][x] == land[y + 1 + i][x])
		{
			visited[y + 1] = 1;
			visited[y + 1 + i] = 1;
			total++;
		}
	}

	if (total == num)
		return 1;
	else
		return 0;			// 1이면 Pass 0이면 Fail
}