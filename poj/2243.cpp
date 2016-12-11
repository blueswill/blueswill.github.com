#include<iostream>
#include<vector>
#include<deque>
#include<cstring>
int chess[8][8];

int diff[][2]{{1,2},{1,-2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,1},{-2,-1}};
using namespace std;
inline bool out_of_bound(int i,int j)
{
    return i<0||j<0||i>=8||j>=8;
}

int main(void)
{
    deque<int> n1,n2;
    int i1,j1,i2,j2;
    string t1,t2;
    while(cin>>t1>>t2)
    {
        n1.clear();
        n2.clear();
        memset(chess,0,sizeof(chess));
        i1=t1[0]-'a';
        i2=t2[0]-'a';
        j1=t1[1]-'0'-1;
        j2=t2[1]-'0'-1;
        int weigh=1;
        n1.push_back(i1);
        n2.push_back(j1);
        while(!n1.empty())
        {
            int s=n1.size();
            int i;
            for(i=0;i<s;++i)
            {
                chess[n1.front()][n2.front()]=weigh;
                if(n1.front()==i2&&n2.front()==j2)
                    break;
                for(int j=0;j<8;++j)
                {
                    int knight[2]{n1.front(),n2.front()};
                    knight[0]+=diff[j][0];
                    knight[1]+=diff[j][1];
                    if(!out_of_bound(knight[0],knight[1])&&chess[knight[0]][knight[1]]==0)
                    {
                        n1.push_back(knight[0]);
                        n2.push_back(knight[1]);
                    }
                }
                n1.pop_front();
                n2.pop_front();
            }
            if(i!=s)
                break;
            ++weigh;
        }
        cout<<"To get from "<<t1<<" to "<<t2<<" takes "<<weigh-1<<" knight moves.\n";
    }
    return 0;
}
