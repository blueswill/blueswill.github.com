#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
	int n,m;
	double res=0.;
	while(cin>>n>>m&&(n||m))
	{
		int i=n,j=m;
		int k=n-m;
		res=1.;
		while(n>0)
		{
			if(k==0)
			{
				res=1;
				break;
			}
			res*=double(n)/(m*k);
			--m;
			--n;
			--k;
			if(!m)
				m=1;
			if(!k)
				k=1;
		}
		printf("%d things taken %d at a time is %.0f exactly.\n",i,j,res);
	}
	return 0;
}
