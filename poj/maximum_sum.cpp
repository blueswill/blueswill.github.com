/*poj 2479*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::max;
const int N=50001;
int data[N];
int left[N];
int right[N];

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>data[i];
	left[0]=*data;
	for(int i=1;i<n;i++)
	{
	    left[i]=left[i-1]+data[i];
	    if(left[i-1]<0)
		left[i]=data[i];
	}
	right[n-1]=data[n-1];
	for(int i=n-2;i>=0;i--)
	{
	    right[i]=right[i+1]+data[i];
	    if(right[i+1]<0)
		right[i]=data[i];
	}
	for(int i=1;i<n;i++)
	{
	    left[i]=max(left[i-1],left[i]);
	    right[n-1-i]=max(right[n-1-i],right[n-i]);
	}
	int p=INT_MIN;
	for(int k=0;k<n;k++)
	{
	    int result=left[k]+right[k+1];
	    if(p<result)
		p=result;
	}
	cout<<p<<endl;
	cout<<endl;
    }
    return 0;
}
