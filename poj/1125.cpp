#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int u,v;
    int weight;
    node(int u,int v,int weight):u(u),v(v),weight(weight){}
};

vector<int> dist;
vector<node> edge;

inline void relax(const node &n){
    if(dist[n.v]>dist[n.u]+n.weight)
        dist[n.v]=dist[n.u]+n.weight;
}

int main(void){
    int N;
    while(cin>>N&&N){
        dist.resize(N);
        edge.clear();
        for(int i=0;i<N;++i){
            int n;
            cin>>n;
            int v,t;
            for(int j=0;j<n;++j){
                cin>>v>>t;
                edge.push_back(node(i,v-1,t));
            }
        }
        int M=999999,pos;
        int i;
        for(i=0;i<N;++i){
            for(int j=0;j<N;++j) dist[j]=999999;
            dist[i]=0;
            for(int a=0;a<N;++a)
                for(unsigned b=0;b<edge.size();++b)
                    relax(edge[b]);
            vector<int>::iterator res=max_element(dist.begin(),dist.end());
            if(*res<M){
                M=*res;
                pos=i+1;
            }
        }
        if(M!=999999)
            cout<<pos<<' '<<M<<endl;
        else
            cout<<"disjoint\n";
    }
    return 0;
}
