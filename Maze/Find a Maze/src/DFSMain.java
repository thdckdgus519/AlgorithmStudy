import java.util.Scanner;

// 시작과 끝도 포함시킨다. 1은 이동 0은 이동 X 
public class DFSMain 
{
	static int maze[][];
	static int visited[];
	static int end_y;
	static int end_x;
	static int min;
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		end_y = sc.nextInt();
		end_x = sc.nextInt();
		min = end_y*end_x;
		
		maze = new int[end_y][end_x];
		visited = new int[end_y*end_x];
		
		for(int i = 0 ; i < end_y ; i++)
		{
			String input = sc.next();
			for(int j = 0 ; j < end_x ; j++)
				maze[i][j] = input.charAt(j) - 48;
		}

		dfs(0,0,1);
		
		System.out.println(min);
	}
	
	public static void dfs(int y, int x, int cnt)
	{
		if( y == end_y-1 && x == end_x-1 )
		{
			if(min > cnt)
				min = cnt;
			return;
		}
		visited[end_x*y + x] = 1;
		
		if( (x < end_x - 1) && (maze[y][x+1] == 1) && (visited[end_x*y + x+1] == 0) )
			dfs(y,x+1,cnt+1);
		if( (y < end_y - 1) && (maze[y+1][x] == 1) && (visited[end_x*(y+1) + x] == 0))
			dfs(y+1,x,cnt+1);
		if( (x > 0) && (maze[y][x-1] == 1) && (visited[end_x*y + x-1] == 0) )
			dfs(y,x-1,cnt+1);
		if( (y > 0) && (maze[y-1][x] == 1) && (visited[end_x*(y-1) + x] == 0))
			dfs(y-1,x,cnt+1);
		
		visited[end_x*y + x] = 0;
	}
}
