import java.util.Scanner;

public class Main 
{
	static char graph[][];
	static int visited[];
	static int mvfinal;

	static int y;
	static int x;
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		y = sc.nextInt();
		x = sc.nextInt();
		graph = new char[y][x];
		visited = new int[26];
//		int move = 0;
		
		for(int i = 0 ; i < y ; i++)
		{
			String input = sc.next();
			for(int j = 0 ; j < x ; j++)
			{
				graph[i][j] = input.charAt(j);
			}
		}
		
		dfs(0,0,1);
		
		System.out.println(mvfinal);
	}
	
	public static void dfs(int ty, int tx, int move)
	{
		if(mvfinal < move)
			mvfinal = move;
		visited[(int)graph[ty][tx] - 65] = 1;
		
		if ( (tx < x - 1) && (visited[(int)graph[ty][tx+1] - 65] == 0) )
			dfs(ty,tx+1,move+1);
		if ( (ty < y - 1) && (visited[(int)graph[ty+1][tx] - 65] == 0) )
			dfs(ty+1,tx,move+1);
		if ( (tx > 0) && (visited[(int)graph[ty][tx-1] - 65] == 0) )
			dfs(ty,tx-1,move+1);
		if ( (ty > 0) && (visited[(int)graph[ty-1][tx] - 65] == 0) )
			dfs(ty-1,tx,move+1);
		
		visited[(int)graph[ty][tx] - 65] = 0;
	}
}
