#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int result[10][10];
int LCS_MEM(const char *a,const char *b,int a1,int b1)
{
    if(a1==0||b1==0)
    {
	result[a1][b1]=0;
	return 0;
    }
    if(result[a1][b1]>=0)
	return result[a1][b1];
    if(a[a1-1]==b[b1-1])
    {
	result[a1][b1]=LCS_MEM(a,b,a1-1,b1-1)+1;
    }
    else
    {
	result[a1][b1]=max(LCS_MEM(a,b,a1-1,b1),LCS_MEM(a,b,a1,b1-1));
    }
    return result[a1][b1];
}

int LCS(const char *a,const char *b)
{
    for(int i=0;a[i];i++)
    {
	for(int j=0;b[j];j++)
	{
	    if(a[i]==b[j])
		result[i+1][j+1]=result[i][j]+1;
	    else if(result[i+1][j]>result[i][j+1])
		result[i+1][j+1]=result[i+1][j];
	    else
		result[i+1][j+1]=result[i][j+1];
	}
    }
    return result[strlen(a)][strlen(b)];
}

void print_LCS(int a,int b,const char *a1,const char *b1)
{
    if(a==0||b==0)
	return;
    int i=a;
    int j=b;
    if(result[i][j]-1==result[i-1][j-1]&&a1[i-1]==b1[j-1])
    {
	print_LCS(i-1,j-1,a1,b1);
	cout<<a1[i-1];
    }
    else if(result[i][j]==result[i-1][j])
	print_LCS(i-1,j,a1,b1);
    else
    	print_LCS(i,j-1,a1,b1);
    return;
}
/*int main(void)
{
    string a,b;
    cin>>a;
    cin>>b;
    cout<<LCS(a.c_str(),b.c_str())<<endl;
    for(int i=0;i<10;i++)
    {
	for(int j=0;j<10;j++)
	    cout<<result[i][j]<<' ';
	cout<<endl;
    }
    print_LCS(a.size(),b.size(),a.c_str(),b.c_str());
    return 0;
}*/ 

int main(void)
{
    char a[100];
    char b[100];
    cin>>a;
    b[strlen(a)]='\0';
    for(int i=strlen(a)-1,j=0;i>=0;i--,j++)
	b[j]=a[i];
    cout<<LCS(a,b)<<endl;
    print_LCS(strlen(a),strlen(b),a,b);
    cout<<endl;
    return 0;
}
