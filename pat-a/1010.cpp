#include"iostream"
#include <sstream> 
#include"string"
//下界字符串字符加1，上界 目标值加1，遍历超时。二分法，注意字符只有一位时的特殊情况 
//另外有可能溢出 
//long long maxn=0x7fffffffffffffff;
using namespace std;
long long convert(string s,long long  radix)
{
	long long sum=0,last=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<='9')
		sum=sum*radix+s[i]-'0';
		else
		sum=sum*radix+s[i]-'a'+10;
		if(sum<last) 
		return -1;//溢出检测 
		last=sum;
	}
	return sum;
}

long long  getmin(string s)
{
	long long  m=0;
	for(int i=0;i<s.length();i++)
	{
		int t;
		if(s[i]<='9')
		t=s[i]-'0';
		else
		t=s[i]-'a'+10;
		if(m<t)
		m=t;
	}
	return m+1;
}
void run()
{
	string a,b;
	long long tag,ra;//	stringstream strs("123");
	cin>>a>>b>>tag>>ra;

	if(tag==2)
	{
		string tmp=a;
		a=b;
		b=tmp;
	}
	//a ra
	long long t=convert(a,ra);
	long long  upper=t+1;
	long long  lower=getmin(b);
	if(upper<lower+3)
	upper=lower+5;
	
	if(b.length()==1) 
	{
		int t2;
		if(b[0]<='9')
		t2=b[0]-'0';
		else
		t2=b[0]-'a'+10;
		if(t==t2)
		cout<<t2+1;
		else
		cout<<"Impossible";
		return;
	}
	
	while(1){
		long long  mid=(lower+upper)/2;
		long long t2=convert(b,mid);
	//	cout<<lower<<" "<<upper<<" "<<mid<<" "<<t2<<endl;
		if(t2==t)
		{
			cout<<mid;
			break;
		}
		else{
			if(lower==(upper-1))
			{
				cout<<"Impossible";
				break;
			}
			if(t2==-1)//overflow
			{
				upper=mid;
			}
			else if(t2<t)
			{
				lower=mid;
			}
			else{
				upper=mid;
			}
		}
 
	}

}

int main()
{
run();	
}