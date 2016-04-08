/*there are squares 3x4, in which we choose five that adhesive to each other.
 * statements excluded are to print the result.
 * It output the number.
 */
#include<iostream>
using namespace std;
const int L=3;
const int W=4;
int A[L][W];
int M=5;
long sum;
void dp(int l,int b,int n,int left)
{
    if(left==0)
    {
	/*for(int i=0;i<L;i++)
	{
	    for(int j=0;j<W;j++)
		cout<<A[i][j]<<' ';
	    cout<<endl;
	}
	cout<<endl;*/
	sum++;
	return;
    }
    if(l==L-2)
    {
	if(left>W)
	    return;
	int begin=b-left+1>=0?b-left+1:0;
	int end=b+n-1+left-1<W?b+n-1:W-left;
	/*for(int k=begin;k<=end;k++)
	{
	    for(int K=k;K<k+left;K++)
		A[L-1][K]=1;
	    for(int i=0;i<L;i++)
	    {
		for(int j=0;j<W;j++)
		    cout<<A[i][j]<<' ';
		cout<<endl;
	    }
	    cout<<endl;
	    for(int K=k;K<k+left;K++)
		A[L-1][K]=0;
	}*/
	sum+=end-begin+1;
	return;
    }
    for(int i=1;i<=W&&i<=left;i++)
    {
	int begin=b-i+1>=0?b-i+1:0;
	int end=b+n-1+i-1<W?b+n-1:W-i;
	for(int j=begin;j<=end;j++)
	{
	    /*for(int k=j;k<j+i;k++)
		A[l+1][k]=1;*/
	    dp(l+1,j,i,left-i);
	    /*for(int k=j;k<j+i;k++)
		A[l+1][k]=0;*/
	}
    }
    return;
}
int main(void)
{
    dp(-1,0,4,5);
    cout<<sum<<endl;
    return 0;
}
