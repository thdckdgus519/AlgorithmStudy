import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main 
{
	static int box[][];
	static Queue<Node> queue;
	static int visited[];
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int box_x = sc.nextInt();
		int box_y = sc.nextInt();
		int check = 0;								// 0이면 이미 다 익은상태.  1이면 덜익은상태.  2이면 결국 익지 못하는상태.
		int day = 0;
		
		box = new int[box_y][box_x];
		queue = new LinkedList<Node>();
		visited = new int[box_y*box_x];
		
		for(int i = 0 ; i < box_y ;i++)
		{
			for(int j = 0 ; j < box_x ; j++)
			{
				box[i][j] = sc.nextInt();
			}
		}
		
		for(int i = 0 ; i < box_y ;i++)
		{
			for(int j = 0 ; j < box_x ; j++)
			{
				if(box[i][j] == 0)
					check = 1;
			}
		}
		
		if(check == 1)
		{
			day = bfs(box_x, box_y);
			
			for(int i = 0 ; i < box_y ;i++)
			{
				for(int j = 0 ; j < box_x ; j++)
				{
					if(box[i][j] == 0)
					{
						if(visited[box_x*i + j] == 0)
						{
							check = 2;
						}
					}
				}
			}
			
		}
		
		if(check == 2)
			System.out.println(-1);
		else
			System.out.println(day);
	}
	
	
	public static int bfs(int box_x, int box_y)
	{
		Node v = null;
		int day = 0;
		
		for(int i = 0 ; i < box_y ;i++)
		{
			for(int j = 0 ; j < box_x ; j++)
			{
				if(box[i][j] == 1)
				{
					queue.add(new Node(i,j,0));
					visited[box_x*i + j] = 1;
				}
			}
		}
		
		while(!queue.isEmpty())
		{
			v = queue.remove();
			day = v.cnt;
			
			if( (v.x < box_x - 1) && ( box[v.y][v.x+1] != -1) && (visited[box_x*(v.y) + (v.x+1)] == 0) )
			{
				queue.add(new Node(v.y,v.x+1,v.cnt+1));
				visited[box_x*(v.y) + (v.x+1)] = 1;
			}
			if( (v.y < box_y -1) &&  ( box[v.y+1][v.x] != -1) && (visited[box_x*(v.y+1) + (v.x)] == 0) )
			{
				queue.add(new Node(v.y+1,v.x,v.cnt+1));
				visited[box_x*(v.y+1) + (v.x)] = 1;
			}
			if( (v.x > 0) && ( box[v.y][v.x-1] != -1) && (visited[box_x*(v.y) + (v.x-1)] == 0) )
			{
				queue.add(new Node(v.y, v.x-1, v.cnt+1));
				visited[box_x*(v.y) + (v.x-1)] = 1;
			}
			if( (v.y > 0) && ( box[v.y-1][v.x] != -1) && (visited[box_x*(v.y-1) + (v.x)] == 0) )
			{
				queue.add(new Node(v.y-1, v.x, v.cnt+1));
				visited[box_x*(v.y-1) + (v.x)] = 1;
			}
		}
		
		return day;
		
		
	}
}

class Node
{
	int y;
	int x;
	int cnt;
	
	public Node(int y, int x,int cnt)
	{
		this.y = y;
		this.x = x;
		this.cnt = cnt;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getCnt() {
		return cnt;
	}

	public void setCnt(int cnt) {
		this.cnt = cnt;
	}
	
	
}
