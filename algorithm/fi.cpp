/* 使用动态规划解决斐波那契数列的问题*/
#include<iostream>
#include<cstring>
using namespace std;
int f(int *l,int t)
{
   if(t==0||t==1)
   {
      l[t]=1;
      return 1;
   }
   if(l[t]>0)
      return l[t];
   l[t]=f(l,t-1)+f(l,t-2);
   return l[t];
}


int Fi(int n)
{
   int *lt=new int[n+1];//cache the temporary result. It can also be set a global variable.
   memset(lt,-1,sizeof(int)*(n+1));
   int result=f(lt,n);
   delete [] lt;
   return result;
}

int main(void)
{
   int i;
   cin>>i;
   cout<<Fi(i)<<endl;
   return 0;
}
