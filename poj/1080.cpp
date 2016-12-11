#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
char src[102],des[102];
int n1,n2;

int table[102][102];

inline int max(int a,int b)
{
    return a>b?a:b;
}

int rate(char a,char b)
{
    if(a=='A')
    {
	switch(b)
	{
	    case 'A':return 5;
	    case 'C':return -1;
	    case 'G':return -2;
	    case 'T':return -1;
	    case '-':return -3;
	}
    }
    if(a=='C')
    {
	switch(b)
	{
	    case 'A':return -1;
	    case 'C':return 5;
	    case 'G':return -3;
	    case 'T':return -2;
	    case '-':return -4;
	}
    }
    if(a=='G')
    {
	switch(b)
	{
	    case 'A':return -2;
	    case 'C':return -3;
	    case 'G':return 5;
	    case 'T':return -2;
	    case '-':return -2;
	}
    }
    if(a=='T')
    {
	switch(b)
	{
	    case 'A':return -1;
	    case 'C':return -2;
	    case 'G':return -2;
	    case 'T':return 5;
	    case '-':return -1;
	}
    }
    if(a=='-')
    {
	switch(b)
	{
	    case 'A':return -3;
	    case 'C':return -4;
	    case 'G':return -2;
	    case 'T':return -1;
	}
    }
}

int main(void)
{
    int T;
    cin>>T;
    while(--T>=0)
    {
	memset(table,0,sizeof(table));
	cin>>n1>>src+1;
	cin>>n2>>des+1;
	for(int i=0;i<=n1;i++)
	    for(int j=0;j<=n2;j++)
	    {
		if(i==0&&j==0)
		    table[i][j]=0;
		else if(i==0)
		    table[i][j]=table[i][j-1]+rate(des[j],'-');
		else if(j==0)
		    table[i][j]=table[i-1][j]+rate(src[i],'-');
		else
		    table[i][j]=max(max(table[i-1][j-1]+rate(src[i],des[j]),table[i][j-1]+rate(des[j],'-')),\
			    table[i-1][j]+rate(src[i],'-'));
	    }
	cout<<table[n1][n2]<<endl;
    }
    return 0;
}
