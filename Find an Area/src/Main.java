import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main 
{
	static int map[][];
	static int visited[];
	static int visited2[];
	static int M;
	static int N;
	static int num;
	static int width;
	static Queue<Node> queue;
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> result = new ArrayList<Integer>();
		queue = new LinkedList<Node>();
		
		M = sc.nextInt();
		N = sc.nextInt();
		int K = sc.nextInt();
		num = 0;
		width = 0;
		
		map = new int[M][N];
		visited = new int[M*N];
		visited2 = new int[M*N];
		
		for(int i = 0 ; i < K ; i++)
		{
			int x1 = sc.nextInt();
			int y1 = M - 1 - sc.nextInt();
			int x2 = sc.nextInt() - 1;
			int y2 = M - sc.nextInt();
			
			for(int j = y2 ; j <= y1 ; j++)
			{
				for(int k = x1 ; k <= x2 ; k++)
				{
						map[j][k] = 1;
				}
			}
		}		
		
		for(int i = 0 ; i < M ; i++)
		{
			for(int j = 0 ; j < N ; j++)
			{
				if(map[i][j] == 0 && visited[N*i + j] == 0)
				{
					result.add(bfs(j,i));
					num++;
					width = 0;
				}
			}
		}
		
		Collections.sort(result);
		System.out.println(num);
		for(int i = 0 ; i < result.size() ; i++)
		{
			System.out.print(result.get(i) + " ");
		}
	}
	
	public static int bfs(int x, int y)
	{
		queue.add(new Node(x,y));
		visited[N*y + x] = 1;
		int c = 1;
		
		while(!queue.isEmpty())
		{
			Node v = queue.remove();
			
			if( (v.x+1 < N) && (map[v.y][v.x+1] == 0) && (visited[N*v.y + v.x+1] == 0) )
			{
				queue.add(new Node(v.x+1,v.y));
				visited[N*v.y + v.x+1] = 1;
				c++;
			}
			if( (v.y+1 < M) && (map[v.y+1][v.x] == 0) && (visited[N*(v.y+1) + v.x] == 0) )
			{
				queue.add(new Node(v.x,v.y+1));
				visited[N*(v.y+1) + v.x] = 1;
				c++;
			}				
			if( (v.x > 0) && (map[v.y][v.x-1] == 0) && (visited[N*v.y + v.x-1] == 0) )
			{
				queue.add(new Node(v.x-1,v.y));
				visited[N*v.y + v.x-1] = 1;
				c++;
			}	
			if( (v.y > 0) && (map[v.y-1][v.x] == 0) && (visited[N*(v.y-1) + v.x] == 0) )
			{
				queue.add(new Node(v.x,v.y-1));
				visited[N*(v.y-1) + v.x] = 1;
				c++;
			}	
		}
		return c;
	}	
}
class Node
{
	int x;
	int y;
	
	public Node(int x,int y)
	{
		this.x = x;
		this.y = y;
	}
}
