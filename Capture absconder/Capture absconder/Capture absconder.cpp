#include<iostream>
#include<queue>
using namespace std;

class Point {
public:
	int x;
	int y;
	int loop;
	Point() {};
	Point(int y, int x, int loop) { this->y = y; this->x = x; this->loop = loop; }
};

int total;
int loop;
void bfs(int**,int*,int,int,int,int,int);

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		total = 1;
		loop = 0;

		int N, M, R, C, L;
		scanf("%d", &N);
		scanf("%d", &M);
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &L);
		
		int** turnel = new int*[N];
		int* visited = new int[N*M];
		for (int i = 0; i < N; i++)
			turnel[i] = new int[M];

		for (int i = 0; i < N*M; i++)
			visited[i] = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int input;
				scanf("%d", &input);
				turnel[i][j] = input;
			}
		}

		bfs(turnel, visited, R, C, L, N, M);
		printf("#%d %d\n", t, total);
		
	}
	return 0;
}

void bfs(int** turnel,int* visited, int y, int x, int L, int N, int M)
{
	queue<Point> q;
	Point p(y, x, 1);
	q.push(p);
	visited[M*p.y + p.x] = 1;
	Point v;

	while (!q.empty())
	{
		v = q.front();
		q.pop();

		if (v.loop == L)
			break;

		if(turnel[v.y][v.x] == 1)
		{
			if ((v.y > 0) && (turnel[v.y - 1][v.x] == 1 || turnel[v.y - 1][v.x] == 2 || turnel[v.y - 1][v.x] == 5 || turnel[v.y - 1][v.x] == 6) && (visited[M*(v.y - 1) + v.x] == 0))		//╩С
			{
				Point temp(v.y - 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y - 1) + v.x] = 1;
				total++;
			}
			if ((v.x + 1 < M) && (turnel[v.y][v.x+1] == 1 || turnel[v.y][v.x+1] == 3 || turnel[v.y][v.x+1] == 6 || turnel[v.y][v.x+1] == 7) && (visited[M*(v.y) + v.x+1] == 0))		// ©Л
			{
				Point temp(v.y, v.x+1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x + 1] = 1;
				total++;
			}
			if ((v.y + 1 < N) && (turnel[v.y+1][v.x] == 1 || turnel[v.y+1][v.x] == 2 || turnel[v.y+1][v.x] == 4 || turnel[v.y+1][v.x] == 7) && (visited[M*(v.y+1) + v.x] == 0))		// го
			{
				Point temp(v.y+1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y + 1) + v.x] = 1;
				total++;
			}
			if ((v.x > 0) && (turnel[v.y][v.x - 1] == 1 || turnel[v.y][v.x - 1] == 3 || turnel[v.y][v.x - 1] == 4 || turnel[v.y][v.x - 1] == 5) && (visited[M*(v.y) + v.x - 1] == 0))		// аб
			{
				Point temp(v.y, v.x - 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x - 1] = 1;
				total++;
			}
		}
		else if(turnel[v.y][v.x] == 2) 
		{
			if ((v.y > 0) && (turnel[v.y - 1][v.x] == 1 || turnel[v.y - 1][v.x] == 2 || turnel[v.y - 1][v.x] == 5 || turnel[v.y - 1][v.x] == 6) && (visited[M*(v.y - 1) + v.x] == 0))		//╩С
			{
				Point temp(v.y - 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y - 1) + v.x] = 1;
				total++;
			}
			if ((v.y + 1 < N) && (turnel[v.y + 1][v.x] == 1 || turnel[v.y + 1][v.x] == 2 || turnel[v.y + 1][v.x] == 4 || turnel[v.y + 1][v.x] == 7) && (visited[M*(v.y + 1) + v.x] == 0))		// го
			{
				Point temp(v.y + 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y + 1) + v.x] = 1;
				total++;
			}
		}
		else if (turnel[v.y][v.x] == 3)
		{
			if ((v.x + 1 < M) && (turnel[v.y][v.x + 1] == 1 || turnel[v.y][v.x + 1] == 3 || turnel[v.y][v.x + 1] == 6 || turnel[v.y][v.x + 1] == 7) && (visited[M*(v.y) + v.x + 1] == 0))		// ©Л
			{
				Point temp(v.y, v.x + 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x + 1] = 1;
				total++;
			}
			if ((v.x > 0) && (turnel[v.y][v.x - 1] == 1 || turnel[v.y][v.x - 1] == 3 || turnel[v.y][v.x - 1] == 4 || turnel[v.y][v.x - 1] == 5) && (visited[M*(v.y) + v.x - 1] == 0))		// аб
			{
				Point temp(v.y, v.x - 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x - 1] = 1;
				total++;
			}
		}
		else if (turnel[v.y][v.x] == 4)
		{
			if ((v.y > 0) && (turnel[v.y - 1][v.x] == 1 || turnel[v.y - 1][v.x] == 2 || turnel[v.y - 1][v.x] == 5 || turnel[v.y - 1][v.x] == 6) && (visited[M*(v.y - 1) + v.x] == 0))		//╩С
			{
				Point temp(v.y - 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y - 1) + v.x] = 1;
				total++;
			}
			if ((v.x + 1 < M) && (turnel[v.y][v.x + 1] == 1 || turnel[v.y][v.x + 1] == 3 || turnel[v.y][v.x + 1] == 6 || turnel[v.y][v.x + 1] == 7) && (visited[M*(v.y) + v.x + 1] == 0))		// ©Л
			{
				Point temp(v.y, v.x + 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x + 1] = 1;
				total++;
			}
		}
		else if (turnel[v.y][v.x] == 5) 
		{
			if ((v.y + 1 < N) && (turnel[v.y + 1][v.x] == 1 || turnel[v.y + 1][v.x] == 2 || turnel[v.y + 1][v.x] == 4 || turnel[v.y + 1][v.x] == 7) && (visited[M*(v.y + 1) + v.x] == 0))		// го
			{
				Point temp(v.y + 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y + 1) + v.x] = 1;
				total++;
			}
			if ((v.x + 1 < M) && (turnel[v.y][v.x + 1] == 1 || turnel[v.y][v.x + 1] == 3 || turnel[v.y][v.x + 1] == 6 || turnel[v.y][v.x + 1] == 7) && (visited[M*(v.y) + v.x + 1] == 0))		// ©Л
			{
				Point temp(v.y, v.x + 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x + 1] = 1;
				total++;
			}
		}
		else if (turnel[v.y][v.x] == 6) 
		{
			if ((v.y + 1 < N) && (turnel[v.y + 1][v.x] == 1 || turnel[v.y + 1][v.x] == 2 || turnel[v.y + 1][v.x] == 4 || turnel[v.y + 1][v.x] == 7) && (visited[M*(v.y + 1) + v.x] == 0))		// го
			{
				Point temp(v.y + 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y + 1) + v.x] = 1;
				total++;
			}
			if ((v.x > 0) && (turnel[v.y][v.x - 1] == 1 || turnel[v.y][v.x - 1] == 3 || turnel[v.y][v.x - 1] == 4 || turnel[v.y][v.x - 1] == 5) && (visited[M*(v.y) + v.x - 1] == 0))		// аб
			{
				Point temp(v.y, v.x - 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x - 1] = 1;
				total++;
			}
		}
		else if (turnel[v.y][v.x] == 7) 
		{
			if ((v.y > 0) && (turnel[v.y - 1][v.x] == 1 || turnel[v.y - 1][v.x] == 2 || turnel[v.y - 1][v.x] == 5 || turnel[v.y - 1][v.x] == 6) && (visited[M*(v.y - 1) + v.x] == 0))		//╩С
			{
				Point temp(v.y - 1, v.x, v.loop + 1);
				q.push(temp);
				visited[M*(v.y - 1) + v.x] = 1;
				total++;
			}
			if ((v.x > 0) && (turnel[v.y][v.x - 1] == 1 || turnel[v.y][v.x - 1] == 3 || turnel[v.y][v.x - 1] == 4 || turnel[v.y][v.x - 1] == 5) && (visited[M*(v.y) + v.x - 1] == 0))		// аб
			{
				Point temp(v.y, v.x - 1, v.loop + 1);
				q.push(temp);
				visited[M*(v.y) + v.x - 1] = 1;
				total++;
			}
		}
		
	}
}