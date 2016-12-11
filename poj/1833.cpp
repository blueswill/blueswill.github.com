#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int table[1024];
int N,K,M;

int main(void)
{
	scanf("%d",&M);
	while(M-->0)
	{
		scanf("%d %d",&N,&K);
		for(int i=0;i<N;++i)
			scanf("%d",&table[i]);
		while(K>0)
		{
			int i,j;
			for(i=N-1;i>0&&table[i]<table[i-1];--i);
			if(!i)//postorder
			{
				sort(table,table+N);
				--K;
				continue;
			}
			for(j=i;j<N&&table[j]>table[i-1];++j);
			--j;
			int tmp=table[j];
			table[j]=table[i-1];
			table[i-1]=tmp;
			sort(table+i,table+N);
			--K;
		}
		copy(table,table+N-1,ostream_iterator<int>(cout," "));//shit output function
		cout<<table[N-1]<<endl;
	}
	return 0;
}
