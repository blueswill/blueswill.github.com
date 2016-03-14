#include<iostream>
#include<algorithm>
using namespace std;
int M,N;
char water[101][101];
int direction[8][2]={{0,1},{0,-1},{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1}};
void del(int m,int n)
{
   for(int i=0;i<8;i++)
   {
      m+=direction[i][0];
      n+=direction[i][1];
      if(m>=0&&n>=0&&m<M&&n<N&&water[m][n]=='W')
      {
	 water[m][n]='.';
	 del(m,n);
      }
      m-=direction[i][0];
      n-=direction[i][1];
   }
   return;
}

void print()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            cout<<water[i][j];
        cout<<endl;
    }
    cout<<endl;
    return;
}

int dfs(void)
{
   int result=0;
   for(int i=0;i<M;i++)
      for(int j=0;j<N;j++)
	 if(water[i][j]=='W')
	 {
	    result++;
	    water[i][j]='.';
	    del(i,j);
            print();
	 }
   return result;
}

int main(void)
{
   cin>>M>>N;
   for(int i=0;i<M;i++)
      for(int j=0;j<N;j++)
	 cin>>water[i][j];
   cout<<dfs()<<endl;
   return 0;
}
