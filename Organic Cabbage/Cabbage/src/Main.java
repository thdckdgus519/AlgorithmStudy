import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main 
{
	static Queue<Node> queue;
	static int visited[];
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Input input[] = new Input[N];
		
		for(int i = 0 ; i < N ; i++)
		{
			int width = sc.nextInt();
			int height = sc.nextInt();
			int location = sc.nextInt();
			int ground[][] = new int[height][width];
			for (int j = 0 ; j < location ; j++)
			{
				int x = sc.nextInt();
				int y = sc.nextInt();
				ground[y][x] = 1;
			}
			
			input[i] = new Input(width,height,location,ground);
		}
			
//////////////////////////////////////////////////////////////////////////////
		
		for(int i = 0 ; i < N ; i++)
		{
			int worm = 0;
			queue = new LinkedList<Node>();
			visited = new int[input[i].width * input[i].height];
			for(int k = 0 ; k < input[i].height ; k++)
			{
				for(int l = 0 ; l < input[i].width ; l++)
				{
					if(input[i].ground[k][l] == 1 && visited[input[i].width*k + l] == 0)
					{
						bfs(k,l,input[i].ground,input[i].width,input[i].height);
						worm++;
					}
				}
			}
			
			System.out.println(worm);
		}
			
		
	}
	
	public static void bfs(int y, int x, int ground[][], int width, int height)
	{
		queue.add(new Node(y,x));
		visited[width * y + x] = 1;
		while(!queue.isEmpty())
		{
			Node v = queue.remove();
			
			if( (v.x < width - 1) && (ground[v.y][v.x + 1] == 1) && (visited[width*v.y + (v.x+1)] == 0) )
			{
				queue.add(new Node(v.y,v.x+1));
				visited[width * v.y + (v.x+1)] = 1;
			}
			if( (v.y < height - 1) && (ground[v.y + 1][v.x] == 1) && (visited[width*(v.y+1) +v.x] == 0) )
			{
				queue.add(new Node(v.y+1,v.x));
				visited[width * (v.y+1) + v.x] = 1;
			}
			if( (v.x > 0) && (ground[v.y][v.x - 1] == 1) && (visited[width*v.y + v.x-1] == 0) )
			{
				queue.add(new Node(v.y,v.x-1));
				visited[width * v.y + v.x-1] = 1;
			}
			if( (v.y > 0) && (ground[v.y-1][v.x] == 1) && (visited[width*(v.y-1) + v.x] == 0) )
			{
				queue.add(new Node(v.y-1,v.x));
				visited[width * (v.y-1) + v.x] = 1;
			}
		}
	}
}

class Input
{
	int width;
	int height;
	int location;
	int ground[][];
	
	public Input(int width, int height, int location, int ground[][])
	{
		this.width = width;
		this.height = height;
		this.location = location;
		this.ground = ground;
	}
}

class Node
{
	int y;
	int x;
	
	public Node(int y, int x)
	{
		this.y = y;
		this.x = x;
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
}
