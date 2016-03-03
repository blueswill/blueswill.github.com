#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *a,int n)
{
   int x=a[n-1];
   int i=-1;
   for(int j=0;j<n;j++)
   {
      if(a[j]<=x)
      {
	 i++;
	 int tmp=a[j];
	 a[j]=a[i];
	 a[i]=tmp;
      }
   }
   return i;
}

void quicksort(int *a,int n)
{
   //has no element
   if(n==0)
      return;
   int p=partition(a,n);
   //exclude the a[p] itself
   quicksort(a,p);
   quicksort(a+p+1,n-1-p);
   return;
}

int main(void)
{
   const int M=5;
   int a[M];
   for(int i=0;i<M;i++)
      a[i]=i+1;
   random_shuffle(a,a+M);
   quicksort(a,M);
   for_each(a,a+M,[](int x){cout<<x<<'\t';});
   cout<<endl;
   return 0;
}
