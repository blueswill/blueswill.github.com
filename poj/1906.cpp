#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;

class BigInteger
{
	private:
		typedef string::size_type size_type;
		typedef string::const_reverse_iterator Iterator;
		string data;
		BigInteger multiplyOne(int i) const;
		int compare(const BigInteger &a,const BigInteger &b,size_type s=0) const
		{
			if(s==0)
				return strcmp(a.data.c_str(),b.data.c_str());
			return strncmp(a.data.c_str(),b.data.c_str(),s);
		}
		template<typename T>
			const string convertToString(T i)
			{
				ostringstream os;
				os<<i;
				return os.str();
			}
	public:
		template<typename T>
			BigInteger(const T &i):data(convertToString(i)){}
		template<typename T>
			BigInteger(const string &i):data(i){}
		template<typename T>
			BigInteger(const char * const p):data(p){}
		BigInteger():data("0"){}
		BigInteger operator+(const BigInteger &) const;
		BigInteger operator-(const BigInteger &) const;
		BigInteger operator*(const BigInteger &) const;
		BigInteger operator/(const BigInteger &) const;
		friend istream &operator>>(istream &is,BigInteger &b)
		{
			return is>>b.data;
		}

		friend ostream &operator<<(ostream & os,const BigInteger &b)
		{
			return os<<b.data;
		}
};

BigInteger BigInteger::operator+(const BigInteger &p) const
{
	string result;
	int left=0;
	for(Iterator i=p.data.crbegin(),j=data.crbegin();i!=p.data.crend()||j!=data.crend();)
	{
		int res=left;
		if(i!=p.data.crend())
		{
			res+=*i-'0';
			++i;
		}
		if(j!=data.crend())
		{
			res+=*j-'0';
			++j;
		}
		left=res/10;
		res%=10;
		result.push_back(res+'0');
	}
	if(left>0)
		result.push_back(left+'0');
	reverse(result.begin(),result.end());
	return BigInteger(result);
}

BigInteger BigInteger::operator-(const BigInteger &p) const
{
	if(compare(*this,p)>0)
	{
	}
	return *this;
}


BigInteger BigInteger::operator*(const BigInteger &p) const
{
	BigInteger result("0");
	for(Iterator i=data.crbegin();i!=data.crend();++i)
	{
		BigInteger tmp=p.multiplyOne(*i-'0');
		int nzero=i-data.crbegin();
		tmp.data+=string(nzero,'0');
		result=result.operator+(tmp);
	}
	return result;
}

BigInteger BigInteger::operator/(const BigInteger &p) const
{
	BigInteger result("0");

	return result;
}

BigInteger BigInteger::multiplyOne(int i) const
{
	string result;
	int left=0;
	for(Iterator j=data.crbegin();j!=data.crend();++j)
	{
		int res=left+(*j-'0')*i;
		left=res/10;
		res%=10;
		result.push_back(res+'0');
	}
	while(left>0)
	{
		result.push_back(left%10+'0');
		left/=10;
	}
	reverse(result.begin(),result.end());
	return BigInteger(result);
}

BigInteger result[65];
bool firstone=true;

int main(void)
{
	result[0]=1;
	for(int i=1;i<65;++i)
		result[i]=result[i-1]*3;
	unsigned long long n;
	while(cin>>n&&n)
	{
		firstone=true;
		cout<<"{";
		if(n&1)
		{
			int index=1;
			n>>=1;
			while(n)
			{
				if(n&1)
				{
					if(!firstone)
					{
						cout<<", ";
						cout<<result[index];
					}
					else
					{
						firstone=false;
						cout<<" "<<result[index];
					}
				}
				n>>=1;
				++index;
			}
		}
		else
		{
			int index=0;
			while(!(n&1))
			{
				if(!firstone)
				{
					cout<<", ";
					cout<<result[index++];
				}
				else
				{
					firstone=false;
					cout<<" "<<result[index++];
				}
				n>>=1;
			}
			n>>=1;
			index++;
			while(n)
			{
				if(n&1)
					cout<<", "<<result[index];
				n>>=1;
				++index;
			}
		}
		cout<<" }\n";
	}
	return 0;
}
