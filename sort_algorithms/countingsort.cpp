#include<iostream>
#include<algorithm>
using namespace std;
void basesort(int *a,int n)
{
   int max=*a;
   for_each(a,a+n,[&max](int x){max=max>x?max:x;});
   int *c=new int[max+1]{0};
   for_each(a,a+n,[c](int x){c[x]++;});
   for(int i=1;i<max+1;i++)
      c[i]+=c[i-1];
   int *result=new int[n];
   for(int i=n-1;i>=0;i--)
      result[--c[a[i]]]=a[i];
   copy(result,result+n,a);
   return;
}

int *basesort(int *begin,int *end)
{
   int max=*begin;
   for_each(begin,end,[&max](int x){max=max>x?max:x;});
   int *c=new int[max+1]{0};
   for(int *tmp=begin;tmp<end;tmp++)
      c[*tmp]++;
   for(int i=1;i<max+1;i++)
      c[i]+=c[i-1];
   int *result=new int[end-begin];
   int *r=result+(end-begin);
   for(int *tmp=end-1;tmp>=begin;tmp--)
   {
      result[--c[*tmp]]=*tmp;
   }
   delete [] c;
   copy(result,r,begin);
   delete []result;
   return begin;
}

int main(void)
{
   const int M=10;
   int a[M]={0};
   for(int i=0;i<M;i++)
      a[i]=i+1;
   random_shuffle(a,a+M);
   basesort(a,M);
   for_each(a,a+M,[](int x){cout<<x<<'\t';});
   cout<<endl;
   return 0;
}
