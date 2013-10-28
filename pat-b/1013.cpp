#include"iostream"
#include"math.h"
using namespace std;
bool isPrime(int t)
{
	if(t<2)
		return false;
	
	int up=sqrt(t);
	for(int i=2;i<=up;i++)
	{
		if(t%i)
		continue;
		return false;
	}
	return true;
}
int main()
{
	int m,n;
	cin>>m>>n;
	int count=0;
	for(int i=2;count<n;i++)
	{ 
		if(isPrime(i))
		{
			count++;
			if(count>=m)
			{
				cout<<i;

				if((count-m+1)%10==0)
					cout<<endl;
				else if(count<n)
					cout<<" ";
					
			}
			
		}
	}
	return 0;
}
