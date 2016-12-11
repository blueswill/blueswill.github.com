#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> Pair;

int main(void)
{
    int N,K;
    cin>>N>>K;
    vector<int> table(K*4,-1);
    queue<Pair> q;
    if(N>K)
    {
        cout<<N-K<<endl;
        return 0;
    }
    q.push({N,0});
    while(q.size()>0)
    {
        Pair cur=q.front();
        q.pop();
        if(cur.first==K)
        {
            cout<<cur.second<<endl;
            return 0;
        }
        if(table[cur.first]>=0)
            continue;
        table[cur.first]=cur.second;
        if(cur.first>K)
            q.push({cur.first-1,cur.second+1});
        else
        {
            if(cur.first>0)
                q.push({cur.first-1,cur.second+1});
            if(cur.first+1<K*4)
                q.push({cur.first+1,cur.second+1});
            if(cur.first*2<K*4)
                q.push({cur.first*2,cur.second+1});
        }
    }
    return 0;
}
