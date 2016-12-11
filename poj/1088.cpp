#include<iostream>
using namespace std;
int table[101][101];
int data[101][101];
int R,C;

int cal(int i,int j)
{
    if(data[i][j]>0)
        return data[i][j];
    int res=0;
    if(j!=C-1&&table[i][j+1]>table[i][j])
    {
        int tmp=cal(i,j+1);
        if(res<tmp)
            res=tmp;
    }
    if(i!=0&&table[i-1][j]>table[i][j])
    {
        int tmp=cal(i-1,j);
        if(res<tmp)
            res=tmp;
    }
    if(j!=0&&table[i][j-1]>table[i][j])
    {
        int tmp=cal(i,j-1);
        if(res<tmp)
            res=tmp;
    }
    if(i!=R-1&&table[i+1][j]>table[i][j])
    {
        int tmp=cal(i+1,j);
        if(res<tmp)
            res=tmp;
    }
    data[i][j]=res+1;
    return data[i][j];
}

int main(void)
{
    cin>>R>>C;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>table[i][j];
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cal(i,j);
    int max=0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(max<data[i][j])
                max=data[i][j];
    cout<<max<<endl;
    return 0;
}
