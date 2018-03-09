package List;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ListDFSBFS
{
	static ArrayList<LinkedList<Integer>> graph;
	static int visited[];
	static Queue<Integer> queue;
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int vertex_num = sc.nextInt();
		int edge_num = sc.nextInt();
		int start_vertex = sc.nextInt() - 1;
		
		graph = new ArrayList<LinkedList<Integer>>(vertex_num);
		visited = new int[vertex_num];
		queue = new LinkedList<Integer>();
		
		for(int i = 0 ; i < vertex_num ; i++)
		{
			graph.add(new LinkedList<Integer>());
		}
		
		for(int i = 0 ; i < edge_num ; i++)
		{
			int begin = sc.nextInt() - 1;
			int end = sc.nextInt() - 1;
			
			graph.get(begin).add(end);
		}
		
//		for(int i = 0 ; i < vertex_num ; i++)
//		{
//			System.out.println(graph.get(i));
//		}
		
		dfs(start_vertex);
		System.out.println();
		for(int i = 0 ; i < visited.length ; i++)
		{
			visited[i] = 0;
		}
		bfs(start_vertex);

	}
	
	public static void dfs(int start_vertex)
	{
		System.out.print((start_vertex+1) + " ");
		visited[start_vertex] = 1;
		
		for(int i = 0; i < graph.get(start_vertex).size() ;i++)
		{
			if( visited[graph.get(start_vertex).get(i)] == 0 )
			{
				dfs(graph.get(start_vertex).get(i));
			}
		}
	}
	
	public static void bfs(int start_vertex)
	{
		System.out.print((start_vertex+1) + " ");
		visited[start_vertex] = 1;
		queue.add(start_vertex);
		while(!queue.isEmpty())
		{
			int v = queue.remove();
			for(int i = 0 ; i < graph.get(v).size() ; i++)
			{
				if(visited[graph.get(v).get(i)] == 0)
				{
					System.out.print((graph.get(v).get(i) + 1) + " ");
					visited[graph.get(v).get(i)] = 1;
					queue.add(graph.get(v).get(i));
				}
			}
		}
	}
}
