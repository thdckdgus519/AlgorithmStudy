import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main 
{
	static int visited[];
	static ArrayList<LinkedList<Integer>> graph;
	static Queue<Integer> queue;
	
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
		
		graph = new ArrayList<LinkedList<Integer>>(vertex);
		visited = new int[vertex];
		queue = new LinkedList<Integer>();
	
		for(int i = 0 ; i < vertex ; i++)
		{
			graph.add(new LinkedList<Integer>());
		}
		for(int i = 0 ; i < num_Edge ; i++)
		{
			input_1 = sc.nextInt()-1;
			input_2 = sc.nextInt()-1;

			if(graph.get(input_1).indexOf(input_2) == -1)
				graph.get(input_1).add(input_2);
			if(graph.get(input_2).indexOf(input_1) == -1)
				graph.get(input_2).add(input_1);
		}
		
		for(int i = 0 ; i < vertex ; i++)
		{
			Collections.sort(graph.get(i));
		}
		
		
		dfs(start_vertex);
		for(int i = 0 ; i < visited.length ; i++)
		{
			visited[i] = 0;
		}
		System.out.println();
		bfs(start_vertex);
	}
	
	public static void dfs(int vertex)
	{
		System.out.print( (vertex+1) + " ");
		visited[vertex] = 1;

		for(int i = 0 ; i < graph.get(vertex).size();i++)
		{
			if(visited[graph.get(vertex).get(i)] == 0)
			{
				dfs(graph.get(vertex).get(i));
			}
		}
	}

	public static void bfs(int vertex)
	{
		int d;
		System.out.print( (vertex+1) + " ");
		visited[vertex] = 1;
		queue.add(vertex);
		
		while(queue.size() != 0)
		{
			d = queue.remove();
			for(int i = 0 ; i < graph.get(d).size() ; i++)
			{
				if(visited[graph.get(d).get(i)] == 0)
				{
					System.out.print( (graph.get(d).get(i) + 1) + " ");
					visited[graph.get(d).get(i)] = 1;
					queue.add(graph.get(d).get(i));
				}
			}
		}
	}
}
