#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int direction[][2]={{-1,-2},{-1,2},{1,-2},{1,2},{2,1},{2,-1},{-2,1},{-2,-1}};
int L;

inline bool valid(int i,int j){
    return i>=0&&i<L&&j>=0&&j<L;
}
bool *flag;

struct node{
    int i,j;
    int step;
    node(int i,int j,int step):i(i),j(j),step(step){}
};

int main(void){
    int N;
    cin>>N;
    while(--N>=0){
        queue<node> q;
        cin>>L;
        flag=new bool[L*L]();
        int si,sj;
        int ei,ej;
        cin>>si>>sj>>ei>>ej;
        q.push(node(si,sj,0));
        int i,j;
        while(!q.empty()){
            si=q.front().i;
            sj=q.front().j;
            int s=q.front().step;
            q.pop();
            if(si==ei&&sj==ej){
                cout<<s<<endl;
                break;
            }
            flag[si*L+sj]=true;
            for(int k=0;k<8;++k){
                i=si+direction[k][0];
                j=sj+direction[k][1];
                if(valid(i,j)&&flag[i*L+j]==false){
                    q.push(node(i,j,s+1));
                    flag[i*L+j]=true;
                }
            }
        }
        delete[] flag;
    }
}
