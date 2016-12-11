#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
unsigned N[]={0,1, 3, 8, 22, 64, 196, 625, 2055, 6917, 23713, 82499, 290511, 1033411, 3707851, 13402696, 48760366, 178405156, 656043856};

inline unsigned getn(unsigned i){
    if(i==0) return 1;
    return N[i]-N[i-1];
}

string constructor(unsigned n){
    if(n==0) return "";
    if(n==1) return "X";
    unsigned i=0,j=0;
    for(;i<18&&N[i]<n;++i);
    unsigned sum=N[i-1];
    for(;j<i;++j){
        if(sum+getn(j)*getn(i-1-j)>=n) break;
        sum+=getn(j)*getn(i-1-j);
    }
    unsigned m=1;
    for(;m*getn(i-1-j)<n-sum;++m);
    string left,right;
    if(j==0){
        left="";
        right=constructor(N[i-2-j]+n-sum);
    }
    else if(m*getn(i-1-j)==n-sum){
        left=constructor(N[j-1]+m);
        if(i-1-j==0) right="";
        else right=constructor(N[i-1-j]);
    }
    else{
        left=constructor(N[j-1]+m);
        if(i-1-j==0) right="";
        else right=constructor(N[i-2-j]+(n-sum)%getn(i-1-j));
    }
    string result;
    if(!left.empty()) result+="("+left+")";
    result+="X";
    if(!right.empty()) result+="("+right+")";
    return result;
}

int main(void){
    unsigned n;
    while(cin>>n&&n)
        cout<<constructor(n)<<endl;
    return 0;
}
