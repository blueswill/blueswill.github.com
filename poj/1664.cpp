#include<iostream>
using namespace std;

int cal(int n,int k)
{
    int sum=0;
    if(k==1)
        return 1;
    if(n==k)
        return cal(n,k-1)+1;
    if(n<k)
        return cal(n,k-1);
    sum+=cal(n,k-1);
    sum+=cal(n-k,k);
    return sum;
}

int main(void)
{
    int N,n,k;
    cin>>N;
    while(--N>=0)
    {
        cin>>n>>k;
        cout<<cal(n,k)<<endl;
    }
    return 0;
}
