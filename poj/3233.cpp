#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class matrix{
    private:
        typedef unsigned long long value_type;
        typedef unsigned long long size_type;
        size_type N;
        value_type *data;
    public:
        static matrix ONE(size_type n){
            matrix one(n);
            for(size_type i=0;i<n;++i) one.data[i*n+i]=1;
            return one;
        }
        size_type size() const{return N;}
        matrix(size_type N=1):N(N),data(new value_type[N*N]()){}
        template<typename T>
            matrix(T begin,T end,size_type N):N(N),data(new value_type[N*N]()){
                int size=0;
                for(T iter=begin;size<N*N&&iter!=end;++iter)
                    data[size++]=*iter;
            }
        matrix(const matrix &m):N(m.N),data(new value_type[N*N]()){
            memmove(data,m.data,sizeof(value_type)*N*N);
        }
        matrix(istream &is,size_type N=1):N(N),data(new value_type[N*N]){
            for(size_type i=0;i<N*N;++i) is>>data[i];
        }
        /*
        matrix(matrix &&m):N(m.N),data(m.data){
            m.data=nullptr;
        }
        */
        matrix &operator=(const matrix &m){
            N=m.N;
            delete[] data;
            data=new value_type[N*N]();
            memmove(data,m.data,sizeof(value_type)*N*N);
            return *this;
        }
        /*
        matrix &operator=(matrix &&m){
            N=m.N;
            delete[] data;
            data=m.data;
            m.data=nullptr;
            return *this;
        }
        */
        ~matrix(){delete[] data;}
        matrix operator*(const value_type &n) const{
            matrix tmp(N);
            for(size_type i=0;i<N*N;++i) tmp.data[i]=data[i]*n;
            return tmp;
        }
        matrix operator*(const matrix &m) const{
            if(N!=m.N) return *this;
            matrix tmp(N);
            for(size_type i=0;i<N;++i)
                for(size_type j=0;j<N;++j)
                    for(size_type k=0;k<N;++k)
                        tmp.data[i*N+j]+=this->data[i*N+k]*m.data[k*N+j];
            return tmp;
        }
        matrix operator%(const value_type &n) const{
            matrix tmp(*this);
            for(size_type i=0;i<N*N;++i)
                tmp.data[i]%=n;
            return tmp;
        }
        matrix operator-(const matrix &m) const{
            if(N!=m.N) return *this;
            matrix tmp(*this);
            for(size_type i=0;i<N*N;++i) tmp.data[i]-=m.data[i];
            return tmp;
        }
        inline value_type &get(size_type i,size_type j){
            return data[i*N+j];
        }
        inline value_type get(size_type i,size_type j) const{
            return data[i*N+j];
        }
        inline matrix &operator*=(const value_type &n){
            return *this=*this*n;
        }
        inline matrix &operator*=(const matrix &m){
            return *this=*this*m;
        }
        inline matrix &operator%=(const value_type &n){
            return *this=*this%n;
        }
        inline matrix &operator-=(const matrix &m){
            return *this=*this-m;
        }
};

matrix fastmod(matrix m,unsigned long long n,unsigned long long mod){
    matrix res=matrix::ONE(m.size());
    while(n>0){
        if(n&1) res=(res*m)%mod;
        m=(m*m)%mod;
        n>>=1;
    }
    return res;
}

int main(void){
    typedef unsigned long long ULL;
    ULL n,k,m;
    cin>>n>>k>>m;
    matrix A(n);
    for(ULL i=0;i<n;++i)
        for(ULL j=0;j<n;++j)
            cin>>A.get(i,j);
    vector<ULL> M(4*n*n,0);
    for(ULL i=0;i<n;++i) M[i*2*n+i]=1;
    for(ULL i=0;i<n;++i)
        for(ULL j=0;j<n;++j)
            M[i*(2*n)+j+n]=M[(n+i)*2*n+j+n]=A.get(i,j);
    matrix tmp(M.begin(),M.end(),2*n);
    tmp=fastmod(tmp,k-1,m);
    matrix result(n);
    for(ULL i=0;i<n;++i)
        for(ULL j=0;j<n;++j)
            result.get(i,j)=(tmp.get(i,j)+tmp.get(i,j+n))%m;
    result*=A;
    result%=m;
    for(ULL i=0;i<n;++i)
        for(ULL j=0;j<n;++j){
            cout<<result.get(i,j);
            if(j!=n-1) cout<<' ';
            else cout<<endl;
        }
    return 0;
}
