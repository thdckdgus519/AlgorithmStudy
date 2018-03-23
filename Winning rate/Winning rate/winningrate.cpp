#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	vector<string> vec;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		double A;
		double B;
		double C;
		double D;
		double alice;
		double bob;

		scanf("%lf", &A);
		scanf("%lf", &B);
		scanf("%lf", &C);
		scanf("%lf", &D);
		
		alice = (A / B) * 100;
		bob = (C / D) * 100;


		if (alice == bob)
			vec.push_back("DRAW");
		else if (alice > bob)
			vec.push_back("ALICE");
		else
			vec.push_back("BOB");
	}

	for (int i = 1; i <= T; i++)
	{
		printf("#%d %s\n",i, vec[i-1].c_str());
	}

	system("pause");

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}