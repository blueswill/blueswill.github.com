#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

int main(void){
    stack<int> zero;
    vector<set<int> > number;
    vector<int> in_degree;
    vector<int> result;
    int N;
    cin>>N;
    number.resize(N+1);
    in_degree=vector<int>(N+1,0);
    int tmp;
    for(int i=1;i<=N;++i){
        while(cin>>tmp&&tmp){ number[i].insert(tmp); in_degree[tmp]++;}
    }
    /*
    for(int x:in_degree) cout<<x<<' ';
    cout<<endl;
    */
    for(int i=1;i<=N;++i)
        if(in_degree[i]==0) zero.push(i);
    while(!zero.empty()){
        int cur=zero.top();
        zero.pop();
        result.push_back(cur);
        for(set<int>::iterator x=number[cur].begin();x!=number[cur].end();++x){
            --in_degree[*x];
            if(in_degree[*x]==0) zero.push(*x);
        }
    }
    for(unsigned i=0;i<result.size()-1;++i) cout<<result[i]<<' ';
    cout<<result.back()<<endl;
    return 0;
}
