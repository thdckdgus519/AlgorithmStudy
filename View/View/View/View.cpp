#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	vector<int> total;

	for (int loop = 0; loop < 10; loop++)
	{
		int width;
		int house = 0;
		scanf("%d", &width);

		vector<int> map(width);
		vector<int> result;

		for (int i = 0; i < width; i++)
		{
			int input;
			scanf("%d", &input);
			map[i] = input;
		}

		for (int i = 2; i < width - 2; i++)
		{
			result.push_back(map[i - 1] - map[i]);
			result.push_back(map[i] - map[i + 1]);
			result.push_back(map[i - 2] - map[i]);
			result.push_back(map[i] - map[i + 2]);

			if ((result[0] < 0) && (result[1] > 0))
			{
				if ((result[2] < 0) && (result[3] > 0))
				{
					result[0] *= -1;
					result[2] *= -1;
					sort(result.begin(), result.end());
					house += result[0];
				}
			}
			result.clear();
		}

		total.push_back(house);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("#%d %d\n", i + 1, total[i]);
	}

	return 0;
}