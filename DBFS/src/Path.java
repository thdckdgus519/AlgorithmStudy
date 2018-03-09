import java.util.Scanner;

public class Path 
{
	static int graph[][];
	static int visited[][];
	static int result[][];
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		graph = new int[n][n];
		visited = new int[n][n];
		result = new int[n][n];
		
		for(int i = 0 ; i < n ; i++)
		{	
			for(int j = 0 ; j < n ; j++)
			{
				graph[i][j] = sc.nextInt();
			}
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			dfs(i,i);
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
				System.out.print(result[i][j] + " ");
			System.out.println();
		}
	}
	
	public static void dfs(int criteria, int vertex)
	{
		result[criteria][vertex] = 1;
		visited[criteria][vertex] = 1;
		
		for(int i = 1 ; i < graph.length ; i++)
		{
			if(visited[criteria][i] == 0 && graph[vertex][i] == 1)
				dfs(criteria, i);
		}
	}
}
