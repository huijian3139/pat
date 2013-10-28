#include"iostream"
#include"math.h"
using namespace std;
int isprime(int a)
{
int u=sqrt(a);
for(int i=2;i<=u;i++)
{
	if((a%i)==0)
	{
		return 0;
	}
}
return 1;
}
int main()
{
	int up;
	cin>>up;
	int flag=0;
	int count=0;
	for(int i=3;i<=up;i+=2)
	{
		if(isprime(i))
		{if(flag)
		count++;
		flag=1;
		}
		else
		{
			flag=0;
		}
		
	}
	cout<<count;
}