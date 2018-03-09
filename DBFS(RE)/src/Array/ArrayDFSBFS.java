package Array;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ArrayDFSBFS 
{
	static int graph[][];
	static int visited[];
	static Queue<Integer> queue;
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		int vertex = sc.nextInt();
		int edge = sc.nextInt();
		int start_vertex = sc.nextInt() - 1;
		graph = new int[vertex][vertex];
		visited = new int[vertex];
		queue = new LinkedList<Integer>();
		
		for(int i = 0 ; i < edge ; i++)
		{
			int begin = sc.nextInt() - 1;
			int end = sc.nextInt() - 1;
			
			graph[begin][end] = 1;
			graph[end][begin] = 1;
		}

		dfs(start_vertex);
		System.out.println();
		for(int i = 0 ; i < vertex; i++)
		{
			visited[i] = 0;
		}
		bfs(start_vertex);
	}
	
	public static void dfs(int vertex)
	{
		System.out.print((vertex+1) + " ");
		visited[vertex] = 1;
		
		for(int i = 0; i < graph.length ; i++)
		{
			if(graph[vertex][i] == 1 && visited[i] == 0 )
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
			
			for(int i = 0 ; i < graph.length ;i++)
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
