#include<iostream>
using namespace std;
int main(void)
{
	int M;
	while(cin>>M)
	{
		int init;
		cin>>init;
		for(int i=1;i<M;i++)
		{
			int tmp;
			cin>>tmp;
			init^=tmp;
		}
		if(init==0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	return 0;
}
