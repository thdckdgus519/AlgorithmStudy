#include<iostream>
using namespace std;

class Magnet {
public:					// N = 0, S = 1	
	int direction[8];	// ºÏ, ºÏµ¿, µ¿, ³²µ¿, ³², ³²¼­, ¼­, ºÏ¼­
};

void rotation(Magnet list[], int magnet_num, int d);

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++)
	{
		int K;
		Magnet list[4];
		scanf("%d", &K);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int input;
				scanf("%d", &input);
				list[i].direction[j] = input;
			}
		}

		for (int i = 0; i < K; i++)
		{
			int magnet_num, d;
			scanf("%d", &magnet_num);
			scanf("%d", &d);
			rotation(list, magnet_num-1, d);
		}
		
		int total = list[0].direction[0] * 1 + list[1].direction[0] * 2 + list[2].direction[0] * 4 + list[3].direction[0] * 8;
		printf("#%d %d\n", t, total);
	}

	return 0;
}

void rotation(Magnet list[],int magnet_num, int d)
{
	int rotation_list[4] = { 0,0,0,0 };
	
	rotation_list[magnet_num] = d;
	
	if (magnet_num == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (list[i].direction[2] == list[i + 1].direction[6])
				break;
			else
			{
				rotation_list[i + 1] = rotation_list[i] * -1;
			}
		}
	}
	else if (magnet_num == 1)
	{
		for (int i = 1; i < 3; i++)
		{
			if (list[i].direction[2] == list[i + 1].direction[6])
				break;
			else
				rotation_list[i + 1] = rotation_list[i] * -1;
		}
		for (int i = 1; i > 0; i--)
		{
			if (list[i].direction[6] == list[i - 1].direction[2])
				break;
			else
				rotation_list[i - 1] = rotation_list[i] * -1;
		}
	}
	else if (magnet_num == 2)
	{
		for (int i = 2; i < 3; i++)
		{
			if (list[i].direction[2] == list[i + 1].direction[6])
				break;
			else
				rotation_list[i + 1] = rotation_list[i] * -1;
		}
		for (int i = 2; i > 0; i--)
		{
			if (list[i].direction[6] == list[i - 1].direction[2])
				break;
			else
				rotation_list[i - 1] = rotation_list[i] * -1;
		}
	}
	else if (magnet_num == 3)
	{
		for (int i = 3; i > 0; i--)
		{
			if (list[i].direction[6] == list[i - 1].direction[2])
				break;
			else
				rotation_list[i - 1] = rotation_list[i] * -1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (rotation_list[i] == 0)
		{
			continue;
		}
		else if (rotation_list[i] == 1)
		{
			int temp = list[i].direction[7];
			for (int j = 7; j > 0; j--)
				list[i].direction[j] = list[i].direction[j - 1];
			list[i].direction[0] = temp;
		}
		else if (rotation_list[i] == -1)
		{
			int temp = list[i].direction[0];
			for (int j = 0; j < 7; j++)
				list[i].direction[j] = list[i].direction[j+1];
			list[i].direction[7] = temp;
		}
	}
}