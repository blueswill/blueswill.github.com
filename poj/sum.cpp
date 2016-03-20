/*hdu 1003*/
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
const int N=100001;
int data[N];
int main(void)
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
	int n;
	cin>>n;
	for(int j=0;j<n;j++)
	    cin>>data[j];
	int max,max_f,max_e,cur_f,cur_e;
	max=*data;
	max_f=max_e=cur_f=cur_e=0;
	int cur=*data;
	for(int j=1;j<n;j++)
	{
	    if(cur<0)
	    {
		cur=data[j];
		cur_f=j;
	    }
	    else
		cur+=data[j];
	    if(cur>max)
	    {
		max=cur;
		max_f=cur_f;
		max_e=j;
	    }
	}
	cout<<"Case "<<i<<":\n"<<max<<' '<<max_f+1<<' '<<max_e+1<<endl;
	if(i<t)
	    cout<<endl;
    }
    return 0;
}

