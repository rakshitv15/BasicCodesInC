#include <bits/stdc++.h>
#include <iomanip> 

using namespace std;

bool checkAnswer(int x, int d, string res)
{
	bool answer;
	if(res=="yes") answer = 1;
	else answer = 0;
	if((x%d == 0) == (answer)) return 1;
	else return 0;
}

int main()
{
	srand(time(0));
	int n = rand() % 50 + 1;
	int divisor[] = {2,3,4,5,6,8,9,11};
	int score = 0, i, d, x, probab;
	string ans;
	cout<<"Check the divisibility of the following "<<n<<". Answer 'yes' or 'no' \n";
	for(i=1;i<=n;i++)
	{
		d = divisor[rand() % 8];
		probab = rand() % 3;
		if(probab == 1) x = (rand() % 9999999)*d;
		else x = rand() % 99999999;
		cout<<x<<" by "<<d<<"\n";
		cin>>ans;
		if(checkAnswer(x,d,ans))
		{
			score++;
			cout<<"Correct "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
		}
		else
		{
			cout<<"Wrong   "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
		}
		cout<<"\n";
	}
	return 0;
}