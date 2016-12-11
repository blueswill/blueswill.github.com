#include<iostream>
#include<iterator>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;

vector< long long> table;

long long exp(long long a,long long n)
{
	long long ans=1;
	while(n)
	{
		if(n&1)
			ans*=a;
		a*=a;
		n>>=1;
	}
	return ans;
}

void factor( long long p)
{
	for( long long i=2;i*i<=p;++i)
		if(p%i==0)
		{
			table.push_back(i);
			while(p%i==0)
				p/=i;
		}
	if(p>1)
		table.push_back(p);
}

int main(void)
{
	long long N,M;
	while(cin>>N>>M)
	{
		table.clear();
		factor(M);
		long long res=0;
		for( long long i=1;i<(1<<table.size());++i)
		{
			long long sum=1;
			long long num=0;
			long long tmp=i;
			long long index=0;
			while(tmp>=1)
			{
				if(tmp&1)
				{
					sum*=table[index];
					++num;
				}
				index++;
				tmp>>=1;
			}
			if(num&1)
				res+=exp(M/sum,N);
			else
				res-=exp(M/sum,N);
		}
		cout<<(long long)(exp(M,N)-res)<<endl;
	}
	return 0;
}
