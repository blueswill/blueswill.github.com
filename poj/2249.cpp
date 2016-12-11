#include<iostream>
using namespace std;

int main(void)
{
	int n,m;
	while(cin>>n>>m&&!(n==0&&m==0))
	{
		unsigned long long res=1;
		if(n-m<m)
			m=n-m;
		int ed=n-m;
		while(m>0||n>ed)
		{
			while(m>0&&res%m==0)
				res/=m--;
			if(n>ed)
				res*=n--;
		}
		cout<<res<<endl;
	}
	return 0;
}
