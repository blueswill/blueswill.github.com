#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class BigInteger{
    public:
        typedef unsigned int value_type;
        BigInteger():data(),base(10000){}
        BigInteger(unsigned long long a);
        BigInteger &operator=(const BigInteger &b){ data=b.data;base=b.base; return *this;}

        friend BigInteger operator+(const BigInteger &a,const BigInteger &b);
        BigInteger operator+(value_type v) const{ return *this+BigInteger(v);}
        friend BigInteger operator*(const BigInteger &a,const BigInteger &b);
        BigInteger &operator*=(const BigInteger &b){return *this=*this*b;}
        BigInteger operator/(value_type v) const;
        BigInteger &operator+=(const BigInteger &b){ return *this=*this+b; }
        BigInteger &operator/=(value_type v){ return *this=*this/v;}
        friend ostream &operator<<(ostream &os,const BigInteger &b);
    private:
        vector<value_type> data;
        unsigned base;
};

BigInteger::BigInteger(unsigned long long a):base(10000){
    do{
        data.push_back(a%base);
        a/=base;
    }while(a);
}

BigInteger operator+(const BigInteger &a,const BigInteger &b){
    vector<BigInteger::value_type>::const_iterator v1=a.data.begin(),v2=b.data.begin();
    BigInteger::value_type leave=0;
    BigInteger tmp;
    for(;v1!=a.data.end()||v2!=b.data.end();){
        BigInteger::value_type sum=leave;
        if(v1!=a.data.end()) sum+=*v1++;
        if(v2!=b.data.end()) sum+=*v2++;
        tmp.data.push_back(sum%a.base);
        leave=sum/a.base;
    }
    while(leave){
        tmp.data.push_back(leave%a.base);
        leave=leave/a.base;
    }
    return tmp;
}

BigInteger operator*(const BigInteger &a,const BigInteger &b){
    vector<BigInteger::value_type>::const_iterator v1=a.data.begin();
    BigInteger res;
    for(;v1!=a.data.end();++v1){
        BigInteger tmp;
        tmp.data.resize(v1-a.data.begin(),0);
        BigInteger::value_type leave=0;
        vector<BigInteger::value_type>::const_iterator v2=b.data.begin();
        for(;v2!=b.data.end();++v2){
            BigInteger::value_type sum=*v2*(*v1)+leave;
            tmp.data.push_back(sum%a.base);
            leave=sum/a.base;
        }
        while(leave){
            tmp.data.push_back(leave%a.base);
            leave/=a.base;
        }
        res+=tmp;
    }
    return res;
}

BigInteger BigInteger::operator/(value_type v) const{
    vector<value_type>::const_reverse_iterator v1=data.rbegin();
    BigInteger result;
    value_type leave=0;
    for(;v1!=data.rend();){
        leave=(leave%v)*base+(*v1++);
        result.data.push_back(leave/v);
    }
    leave%=v;
    if(leave>=v) result.data.push_back(leave/v);
    reverse(result.data.begin(),result.data.end());
    while(result.data.back()==0) result.data.pop_back();
    return result;
}

ostream &operator<<(ostream &os,const BigInteger &b){
    typedef vector<BigInteger::value_type>::const_reverse_iterator iterator;
    os<<b.data.back();
    for(iterator v=b.data.rbegin()+1;v!=b.data.rend();++v){
        os<<setw(4)<<setfill('0')<<*v;
    }
    return os;
}

vector<BigInteger> result(101);

int main(void){
    BigInteger tmp(12345678);
    for(unsigned i=0;i<99;++i) tmp*=tmp;
    cout<<tmp<<endl;
    return 0;
}
