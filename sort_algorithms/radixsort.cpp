#include<iostream>
#include<algorithm>
using namespace std;

inline int extract(int a,int n)
{
   return (a>>n)%2;
}

int maxline(int a)
{
   int i;
   for(i=0;i<sizeof(a)*8;i++)
      if((a>>i)==0)
	 return i;
   return i;
}

int *basesort(int *begin,int *end,int i)
{
   int max=*begin;
   for_each(begin,end,[&max,i](int x){max=max>extract(x,i)?max:extract(x,i);});
   int *c=new int[max+1]{0};
   for(int *tmp=begin;tmp<end;tmp++)
      c[extract(*tmp,i)]++;
   for(int i=1;i<max+1;i++)
      c[i]+=c[i-1];
   int *result=new int[end-begin];
   int *r=result+(end-begin);
   for(int *tmp=end-1;tmp>=begin;tmp--)
   {
      int e=extract(*tmp,i);
      result[--c[e]]=*tmp;
   }
   delete [] c;
   copy(result,r,begin);
   delete []result;
   return begin;
}

int main(void)
{
   const int M=100;
   int a[M];
   for(int i=0;i<M;i++)
      a[i]=i+1;
   random_shuffle(a,a+M);
   int max=*a;
   for_each(a,a+M,[&max](int x){max=max>x?max:x;});
   for(int i=0;i<maxline(max);i++)
      basesort(a,a+M,i);
   for_each(a,a+M,[](int x){cout<<x<<'\t';});
   cout<<endl;
   return 0;
}
