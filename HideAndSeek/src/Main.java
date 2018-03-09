import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main
{
	static int visited[];
	static Queue<Node> queue;
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int start = sc.nextInt();
		int end = sc.nextInt();
		int time;
		visited = new int[100001];
		queue = new LinkedList<Node>();
		
		if(start > end)
			time = start-end;
		else if (start == end)
			time = 0;
		else
			time = bfs(start,end);
		
		System.out.println(time);
	}
	public static int bfs(int start, int end)
	{
		queue.add(new Node(start,0));
		visited[start] = 1;
		Node v = null;
		
		while(!queue.isEmpty())
		{
			v = queue.remove();
			if(v.getNum() == end)
				break;
			
			if(((v.getNum()-1) >= 0))
			{
				if(visited[v.getNum()-1] == 0)
				{
					queue.add(new Node(v.getNum()-1, v.getCnt()+1));
					visited[v.getNum()-1] = 1;
				}
			}
			
			if((v.getNum()+1) <= 100000)
			{
				if(visited[v.getNum()+1] == 0)
				{
					queue.add(new Node(v.getNum()+1, v.getCnt()+1));
					visited[v.getNum()+1] = 1;
				}
			}
			
			if((v.getNum()*2) <= 100000)
			{
				if(visited[v.getNum()*2] == 0)
				{
					queue.add(new Node(v.getNum()*2, v.getCnt()+1));
					visited[v.getNum()*2] = 1;
				}
			}
		
		}
		
		return v.getCnt();
	}
}

class Node
{
	private int num;
	private int cnt;
	
	public Node(int num, int cnt)
	{
		this.num = num;
		this.cnt = cnt;
	}
	
	public int getNum() 
	{
		return num;
	}
	public void setNum(int num) 
	{
		this.num = num;
	}
	public int getCnt() 
	{
		return cnt;
	}
	public void setCnt(int cnt) 
	{
		this.cnt = cnt;
	}
}
