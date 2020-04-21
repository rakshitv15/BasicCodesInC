#include <bits/stdc++.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

class gfg 
{ 
	public : 
		int gcd(int a, int b)
		{ 
	    	if (a == 0) return b;  
	    	return gcd(b % a, a);  
	 	}
	  	int lcm(int a, int b)  
	 	{  
	    	return (a*b)/gcd(a, b);  
	 	}  
}; 

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}

bool checkYesOrNo(string a)
{
	if(a == "yes" || a == "Yes" || a == "YES" || a == "no" || a == "No" || a == "NO") return 1;
	else return 0;
}

bool checkDivisibilityAnswer(int x, int d, string res)
{
	bool answer;
	if(res=="yes" || res=="Yes"  || res=="YES") answer = 1;
	else answer = 0;
	if((x%d == 0) == (answer)) return 1;
	else return 0;
}

int generateHCFQ(string f1, string f2)
{
	int probab = rand() % 3;
	int a,b,c,x;
	string HCFQ;
	/*if(probab == 1)
	{ 
		x = (rand() % 101);
		a = x*(rand() % 101);
		b = x*(rand() % 101);
		c = x*(rand() % 101);
	}
	else
	{ 
		a = rand() % 10000;
		b = rand() % 10000;
		c = rand() % 10000;
	}*/
	x = (rand() % 101);
	a = x*(rand() % 101);
	b = x*(rand() % 101);
	c = x*(rand() % 101);
	int q = rand() % 4;
	switch (q)
	{
		case 0:
		{
			HCFQ = "You, " + f1 + " and " + f2 + " are asked by your class teacher to measure " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + " millilitres of water respectively. Find the size in millilitres of the largest vessel that all of you can use one by one to measure\n";
			break;
		}

		case 1:
		{
			HCFQ = "Find the HCF of " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + "\n";
			break;
		}

		case 2:
		{
			HCFQ = "Find the largest number which divides " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + "\n";
			break;
		}
		case 3:
		{
			int ra,rb,rc;
			ra = (rand()%((a+10)/10)+1) % gcd(a,gcd(b,c));
			rb = (rand()%((b+10)/10)+1) % gcd(a,gcd(b,c));
			rc = (rand()%((c+10)/10)+1) % gcd(a,gcd(b,c));
			HCFQ = "Find the largest number which divides " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + " leaving remainder of " + to_string(ra) + ", " + to_string(rb) + " and " + to_string(rc) + " respectively\n";
			a -= ra;
			b -= rb;
			c -= rc;
			break;
		}
	}
	cout<<HCFQ;
	return gcd(a,gcd(b,c));
}

int generateLCMQ(string f1, string f2)
{
	string LCMQ;
	int probab = rand() % 3;
	int a,b,c,x;
	if(probab == 1)
	{ 
		x = (rand() % 26);
		a = x*(rand() % 26);
		b = x*(rand() % 26);
		c = x*(rand() % 26);
	}
	else
	{ 
		a = rand() % 100;
		b = rand() % 100;
		c = rand() % 100;
	}
	int q = rand() % 4;
	int m = 0;
	switch (q)
	{
		case 0:
		{
			LCMQ = "You, " + f1 + " and " + f2 + " start walking from a point and walk " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + " steps at a time respectively. Find the minimum number of steps you and your friends would walk to be together again.\n";
			break;
		}

		case 1:
		{
			LCMQ = "Find the LCM of " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + "\n";
			break;
		}

		case 2:
		{
			LCMQ = "Find the smallest number can be divided by " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + "\n";
			break;
		}
		case 3:
		{
			m = rand()%((min(a-1,min(b-1,c-1)))%16+1);
			LCMQ = "Find the smallest number can be divided by " + to_string(a) + ", " + to_string(b) + " and " + to_string(c) + " leaving remainder of " + to_string(m) + " in all three cases.\n";
			break;
		}
	}
	cout<<LCMQ;
	gfg g;
	return g.lcm(a,g.lcm(b,c))+m;
}

void pretty_cout(string S)
{
	for(int i=0;i<S.size();i++)
	{
		cout<<S[i]<<flush;
		this_thread::sleep_for(0.04s);
	}
}

int main()
{
	srand(time(0));
	int n = (rand() % 10 + 1)*5,x,a,b,c,d;
	int score = 0, i;
	string ans, name, statement, city, temp;
	vector<string> friends;
	pretty_cout("Please tell me your name.\n");
	cin>>name;
	pretty_cout("Hello " + name + "!\n");
	pretty_cout("Where do you live?\n");
	cin>>city;
	this_thread::sleep_for(0.4s);
	pretty_cout("Nice!!\n");
	this_thread::sleep_for(0.4s);
	pretty_cout("Can you name 3 of your friends?\n");
	for(i=0;i<3;i++)
	{
		cin>>temp;
		friends.push_back(temp);
	}
	this_thread::sleep_for(0.4s);
	pretty_cout("Thanks\n\n");
	pretty_cout("Solve the following " + to_string(n) + " questions and master your maths!\n\n");
	for(i=1;i<=n;i++)
	{
		int q = rand() % 3;
		cout<<"Q"<<setw(2)<<i<<": "<<flush;
		switch (q)
		{
			case 0:
			{
				int divisor[] = {2,3,4,5,6,8,9,11};
				d = divisor[rand() % 8];
				int probab = rand() % 3;
				if(probab == 1) x = (rand() % 9999)*d;
				else x = rand() % 999999;
				cout<<"Is "<<x<<" divisible by "<<d<<" ?\n";
				cin>>ans;
				while(!checkYesOrNo(ans))
				{
					cout<<"Please provide a valid answer!\n";
					cin>>ans;
				}
				if(checkDivisibilityAnswer(x,d,ans))
				{
					score++;
					cout<<"Correct "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
				}
				else
				{
					cout<<"Wrong   "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
				}
				break;
			}

			case 1:
			{
				string f1 = friends[rand() % 3], f2;
				f2 = f1;
				while(f1 == f2) f2 = friends[rand() % 3];
				int correct = generateHCFQ(f1,f2);
				cin>>x;
				if(x == correct)
				{
					score++;
					cout<<"Correct "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
				}
				else
				{
					cout<<"Wrong   "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
					cout<<"Answer is "<<correct<<"\n";
				}
				break;
			}

			case 2:
			{
				string f1 = friends[rand() % 3], f2;
				f2 = f1;
				while(f1 == f2) f2 = friends[rand() % 3];
				int correct = generateLCMQ(f1,f2);
				cin>>x;
				if(x == correct)
				{
					score++;
					cout<<"Correct "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
				}
				else
				{
					cout<<"Wrong   "<<setw(20)<<"SCORE: "<<score<<"/"<<i<<endl;
					cout<<"Answer is "<<correct<<"\n";
				}
				break;
			}
		}
		cout<<"\n";
	}
	float scr = score/n;
	cout<<"\nFinal Score: "<<score<<"/"<<n<<endl;
	if(scr == 1) cout<<"Congrats! That's a perfect score. You are on fire today!!!\n";
	if(scr>=0.9 && scr<1) cout<<"That's an excellent score! \nWell Done!\n";
	if(scr>=0.8 && scr<0.9) cout<<"That's a good score.\n";
	if(scr>=0.7 && scr<0.8) cout<<"That's an okayish score.\nYou should work on your concepts! \n";
	if(scr>=0.5 && scr<0.7) cout<<"That's not a good score. \nPlease work hard and try again!\n";
	if(scr<0.5) cout<<"That's a very poor score!\n";
	return 0;
}
