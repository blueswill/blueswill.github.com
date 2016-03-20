/*get the answer of one math expression like 4*3*(12+13)=*/
#include<iostream>
#include<cstdlib>
using namespace std;
int compare(char a,char b)
{
    if(a=='=')
    {
	if(b!=a)
	    return -1;
	else
	    return 0;
    }
    if(a=='('&&b==')')
	return 0;
    if(a=='('&&b!=')')
	return -1;
    if(a!=')'&&b==')')
	return 1;
    int av,bv;
    if(a=='*'||a=='/')
	av=2;
    else
	av=1;
    if(b=='*'||b=='/')
	bv=2;
    else bv=1;
    return av-bv;
}

int merge(char a,int t1,int t2)
{
    if(a=='+')
	return t1+t2;
    if(a=='-')
	return t1-t2;
    if(a=='*')
	return t1*t2;
    if(a=='/')
    {
	if(t2==0)
	{
	    cout<<"error!\n";
	    exit(0);
	}
	return t1/t2;
    }
}

int getnext(char **flag)
{
    char pro=**flag;
    char *begin=(*flag)+1;
    int t2;
    t2=-1;
    if(*begin=='(')
    {
	t2=getnext(&begin);
    }
    else
	t2=(int)strtol(begin,&begin,0);
    while(compare(pro,*begin)<0)
    {
	char p=*begin;
	int tmp;
	tmp=getnext(&begin);
	t2=merge(p,t2,tmp);
    }
    if(*begin==')'&&pro=='(')
	begin++;
    *flag=begin;
    return t2;
}

int main(void)
{
    char data[1000];
    data[0]='=';
    cin>>data+1;
    int result=0;
    char *flag=data;
    result=getnext(&flag);
    cout<<result<<endl;
    return 0;
}
