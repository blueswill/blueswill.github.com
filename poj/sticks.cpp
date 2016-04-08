#include<iostream>
#include<algorithm>
using namespace std;
int n;
int sticks[65];
int status[65];
int length;

bool dfs(int i,int left,int sum)
{
   if(left==0)
   {
      if(sum==0)
	 return true;
      int j;
      for(j=0;j<n;j++)
	 if(status[j]==0)
	    break;
      status[j]=1;
      sum-=sticks[j];
      if(dfs(j+1,length-sticks[j],sum))
	 return true;
      sum+=sticks[j];
      status[j]=0;
   }
   else
   {
      for(int j=i;j<n;j++)
      {
	 if(sticks[j]==sticks[j-1]&&status[j-1]==0)//剪枝，重复元素较多
	    continue;
	 if(status[j]==0&&sticks[j]<=left)
	 {
	    status[j]=1;
	    if(dfs(j+1,left-sticks[j],sum-sticks[j]))
	       return true;
	    status[j]=0;
	    if(sticks[j]==left)
	       break;
	 }
      }
   }
   return false;
}

int main(void)
{
   while(cin>>n&&n)
   {
      for(int i=0;i<n;i++)
      {
	 cin>>sticks[i];
	 status[i]=0;
      }
      sort(sticks,sticks+n,[](int x,int y){return x>y;});
      int max=*sticks;
      for_each(sticks,sticks+n,[&max](int x){max=max>x?max:x;});
      int sum=0;
      for_each(sticks,sticks+n,[&sum](int x){sum+=x;});
      for(int i=max;i<=sum/2;i++)
      {
          length=i;
	 if(dfs(0,i,sum))
	 {
	    cout<<i<<endl;
	    break;
	 }
      }
   }
   return 0;
}
