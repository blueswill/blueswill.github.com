/*this is a program which hasn't been certified*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<climits>
int length[1000];
int data[1000];
int r[1000];
char  str[1000][1000];
const int M=100;
using namespace std;
int result(int n)
{
    if(n<=0)
	return data[0];
    if(data[n]>0)
	return data[n];
    int max=INT_MAX,sum=length[n];
    int N;
    for(int i=n;i>=0&&M-n+i-sum>0;i--,sum+=length[i])
    {
	int tmp=M-n+i-sum;
	tmp=tmp*tmp*tmp+result(i-1);
	if(max>tmp)
	{
	    max=tmp;
	    N=i;
	}
    }
    data[n]=max;
    r[n]=N;
    return max;
}

void print(int n)
{
    if(n<=0)
	return;
    print(r[n]);
    for(int i=r[n];i<n;i++)
	cout<<str[i]<<' ';
    cout<<endl;
    return;
}

int main(int argc,char **argv)
{
    ifstream fin(argv[1]);
    if(!fin.is_open())
	return -1;
    int *t=length;
    int i=0;
    while(fin>>str[i++])
	*t++=strlen(str[i-1]);
    cout<<result(t-length)<<endl;
    print(t-length);
    cout<<endl;
    return 0;
}
