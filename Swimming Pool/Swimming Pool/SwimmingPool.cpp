#include<iostream>
#include<algorithm>
using namespace std;

int min_1(int a, int b)
{
	return min(a, b);
}
int min_2(int a, int b, int c)
{
	return min(min(a, b), c);
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int one_day;
		int one_month;
		int three_month;
		int one_year;
		
		int month[12];
		int result[12];
		
		scanf("%d", &one_day);
		scanf("%d", &one_month);
		scanf("%d", &three_month);
		scanf("%d", &one_year);

		for (int i = 0; i < 12; i++)
		{
			int input;
			scanf("%d", &input);
			month[i] = input;
		}

		for (int i = 0; i < 12; i++)
		{
			if (i == 0)
			{
				result[i] = min_1(month[i] * one_day, one_month);
			}
			else if (i == 1)
			{
				result[i] = min_1(month[i] * one_day, one_month) + result[i - 1];
			}
			else if (i == 2)
			{
				result[i] = min_2(result[i - 1] + (month[i] * one_day), result[i - 1] + one_month, three_month);
			}
			else
			{
				result[i] = min_2(result[i - 1] + (month[i] * one_day), result[i - 1] + one_month, result[i - 3] + three_month);
			}
		}

		result[11] = min(result[11], one_year);

		printf("#%d %d\n", t, result[11]);

	}
	return 0;
}