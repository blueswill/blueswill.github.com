#include<iostream>
#include<algorithm>
int map[11]={0,1,5,8,9,10,17,17,20,24,30};
int r[11];
int s[11];
int price(int length)
{
    if(length==0||r[length]>0)
	return r[length];
    int maxprice=0;
    for(int i=1;i<=length;i++)
    {
	int tmp=map[i]+price(length-i);
	if(maxprice<tmp)
	{
	    s[length]=i;
	    maxprice=tmp;
	}
    }
    r[length]=maxprice;
    return maxprice;
}

void printlength(int length)
{
    if(length==0)
	return;
    std::cout<<s[length]<<' ';
    printlength(length-s[length]);
    return;
}

int main(void)
{
    std::cout<<price(10)<<std::endl;
    printlength(10);
    std::cout<<std::endl;
    return 0;
}
