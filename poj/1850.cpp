#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;
string table;
unsigned long long num[27][27];

void valid(const string &s)
{
	for(int i=1;s[i];++i)
		if(s[i]<=s[i-1])
		{
			cout<<0<<endl;
			exit(0);
		}
}

int main(void)
{
	cin>>table;
	valid(table);
	int len=table.size();
	if(len==1)
	{
		cout<<table[0]-'a'+1<<endl;
		return 0;
	}
	for(int i=0;i<26;++i)
		num[1][i]=1;
	for(int i=2;i<27;++i)
	{
		for(int j=1;j<26;++j)
			num[i][0]+=num[i-1][j];
		for(int j=1;j<26;++j)
			num[i][j]=num[i][j-1]-num[i-1][j];
	}
	for(int i=1;i<27;++i)
		for(int j=0;j<26;++j)
			num[i][26]+=num[i][j];
	unsigned long long result=0;
	for(int i=0;i<len;++i)
		result+=num[i][26];
	for(int i=0;i<*table.begin()-'a';++i)
		result+=num[len][i];
	for(string::iterator i=table.begin()+1;i!=table.end();++i)
	{
		int l=table.end()-i;
		for(int j=*(i-1)-'a'+1;j<*i-'a';++j)
			result+=num[l][j];
	}
	cout<<result+1<<endl;
	return 0;
}

