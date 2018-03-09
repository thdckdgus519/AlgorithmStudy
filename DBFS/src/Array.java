import java.util.LinkedList;
import java.util.Scanner;

public class Array 
{
	static int graph[][];
	static int visited[];
	static LinkedList<Integer> queue;
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int vertex;
		int num_Edge;
		int start_vertex;
		int input_1;
		int input_2;
		
		vertex = sc.nextInt();
		num_Edge = sc.nextInt();
		start_vertex = sc.nextInt();
		start_vertex -= 1;
		
		graph = new int[vertex][vertex];
		visited = new int[vertex];
		queue = new LinkedList<Integer>();
		
		for(int i = 0 ; i < num_Edge ; i++)
		{
			input_1 = sc.nextInt() - 1;
			input_2 = sc.nextInt() - 1;
			
			if(graph[input_1][input_2] != 1)
				graph[input_1][input_2] = 1;
			if(graph[input_2][input_1] != 1)
				graph[input_2][input_1] = 1;
		}
		dfs(start_vertex);
		System.out.println();
		for(int i = 0 ; i < visited.length ; i++)
		{
			visited[i] = 0;
		}
		bfs(start_vertex);
	}
	
	public static void dfs(int vertex)
	{
		System.out.print((vertex+1) + " ");
		visited[vertex] = 1;
		
		for(int i = 1 ; i < graph.length ; i++)
		{
			if(visited[i] == 0 && graph[vertex][i] == 1)
			{
				dfs(i);
			}
		}
	}
	
	public static void bfs(int vertex)
	{
		System.out.print((vertex+1) + " ");
		visited[vertex] = 1;
		queue.add(vertex);
		while(!queue.isEmpty())
		{
			int v = queue.remove();
			for(int i = 1 ; i < graph.length ; i++)
			{
				if(graph[v][i] == 1 && visited[i] == 0)
				{
					System.out.print((i+1) + " ");
					visited[i] = 1;
					queue.add(i);
				}
			}
		}
	}
}

