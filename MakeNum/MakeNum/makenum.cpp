#include<iostream>
#include<vector>
using namespace std;

int Min = 100000000;
int Max = -100000000;
void dfs(int, int, int, int*, int*);

int main(void)
{
	int T;
	scanf("%d", &T);
	Min = 100000000;
	Max = -100000000;
	for (int i = 1; i <= T; i++)
	{
		int N;
		scanf("%d", &N);

		int* num = new int[N];
		int* modify = new int[4];

		for (int j = 0; j < 4; j++)
		{
			int m;
			scanf("%d", &m);
			modify[j] = m;
		}

		for (int j = 0; j < N; j++)
		{
			int n;
			scanf("%d", &n);
			num[j] = n;
		}

		dfs(1, N, num[0], num, modify);
		int r = Max - Min;
		printf("#%d %d\n", i, r);
		Min = 100000000;
		Max = -100000000;
	}

	return 0;
}

void dfs(int n, int N, int sum, int* num, int* modify)
{
	cout << "sum : " << sum << endl;
	if (n == N)
	{

		if (Min > sum)
			Min = sum;
		if (Max < sum)
			Max = sum;
		return;
	}
	if (modify[0] != 0)
	{
		modify[0]--;
		dfs(n + 1, N, sum + num[n], num, modify);
		modify[0]++;
	}
	if (modify[1] != 0)
	{
		modify[1]--;
		dfs(n + 1, N, sum - num[n], num, modify);
		modify[1]++;
	}
	if (modify[2] != 0)
	{
		modify[2]--;
		dfs(n + 1, N, sum * num[n], num, modify);
		modify[2]++;
	}
	if (modify[3] != 0)
	{
		modify[3]--;
		dfs(n + 1, N, sum / num[n], num, modify);
		modify[3]++;
	}

}