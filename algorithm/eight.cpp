#include<iostream>
using namespace std;
const int N=14;
int A[N][N];
int sum=0;
int valid(int deep,int ps)
{
    for(int i=0;i<deep;i++)
	if(A[i][ps])
	    return 0;
    for(int i=deep-1,j=ps-1;i>=0&&j>=0;i--,j--)
	if(A[i][j])
	    return 0;
    for(int i=deep-1,j=ps+1;i>=0&&j<N;i--,j++)
	if(A[i][j])
	    return 0;
    return 1;
}

void dp(int deep,int ps)
{
    if(deep==N-1)
    {
	sum++;
	return;
    }
    //search for next line
    for(int i=0;i<N;i++)
    {
	if(valid(deep+1,i))
	{
	    A[deep+1][i]=1;
	    dp(deep+1,i);
	    A[deep+1][i]=0;
	}
    }
    return;
}

int main(void)
{
    dp(-1,-1);
    cout<<sum<<endl;
    return 0;
}
