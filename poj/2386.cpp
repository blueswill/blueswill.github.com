#include<iostream>
#include<queue>
#include<utility>
#include<stack>
using namespace std;
int N,M;
char table[101][101];
typedef pair<int,int> Pair;

inline bool inbound(int i,int j)
{
    return i>=0&&i<N&&j>=0&&j<M&&table[i][j]=='W';
}
void search_one(int i,int j)
{
    if(table[i][j]=='W')
    {
        table[i][j]='.';
        for(int a=i-1;a<i+2;++a)
            for(int b=j-1;b<j+2;++b)
                if(inbound(a,b))
                    search_one(a,b);
    }
}

int main(void)
{
    cin>>N>>M;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            cin>>table[i][j];
    int sum=0;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            if(table[i][j]=='W')
            {
                ++sum;
                search_one(i,j);
            }
    cout<<sum<<endl;
    return 0;
}
