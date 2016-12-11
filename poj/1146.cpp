#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string input;
    while(cin>>input&&input!="#"){
        unsigned i=0,j=0;
        for(i=input.size()-1;i>0&&input[i]<=input[i-1];--i);
        if(i==0){
            cout<<"No Successor\n";
            continue;
        }
        for(j=input.size()-1;j>i-1&&input[j]<=input[i-1];--j);
        swap(input[i-1],input[j]);
        sort(input.begin()+i,input.end());
        cout<<input<<endl;
    }
    return 0;
}
