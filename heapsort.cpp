#include<iostream>
#include<algorithm>
using namespace std;

inline int left(int i)
{
   return 2*i+1;
}

inline int right(int i)
{
   return 2*i+2;
}

inline int parent(int i)
{
   return (i-1)/2;
}

void MAX_HEAP(int *a,int i,int n)
{
   int l=left(i);
   int r=right(i);
   int largest;
   while(l<n)
   {
      if(a[i]>a[l])
	 largest=i;
      else
	 largest=l;
      if(r<n&&a[r]>a[largest])
	 largest=r;
      if(largest!=i)
      {
	 int tmp=a[i];
	 a[i]=a[largest];
	 a[largest]=tmp;
	 i=largest;
	 l=left(largest);
	 r=right(largest);
	 continue;
      }
      break;
   }
}

void BUILD_HEAP(int *a,int n)
{
   for(int i=n/2-1;i>=0;i--)
      MAX_HEAP(a,i,n);
}

void hsort(int *a,int n)
{
   if(n==1)
      return;
   BUILD_HEAP(a,n);
   int tmp=a[n-1];
   a[n-1]=a[0];
   a[0]=tmp;
   hsort(a,n-1);
}

int main(void)
{
   int a[100];
   for(int i=0;i<100;i++)
      a[i]=i+1;
   random_shuffle(a,a+100);
   hsort(a,100);
   for_each(a,a+100,[](int x){cout<<x<<'\t';});
   return 0;
}
