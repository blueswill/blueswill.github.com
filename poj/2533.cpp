#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<climits>

using namespace std;

int main(void)
{
    int N;
    while(cin>>N)
    {
        vector<int> seq(N);
        for(int i=0;i<N;++i)
            cin>>seq[i];
        vector<int> result(N,0);
        result[0]=1;
        for(int i=1;i<N;++i)
        {
            for(int j=0;j<i;++j)
                if(seq[j]<seq[i]&&result[i]<=result[j])
                    result[i]=result[j]+1;
            result[i]=max(1,result[i]);
        }
        cout<<*max_element(result.begin(),result.end())<<endl;
    }
    return 0;
}
