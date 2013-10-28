#include"iostream"
#define for(n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for(n)
	cin>>a[i];
	for(n)
	{
		int index=i-m;
		while(index<0)index+=n;
		cout<<a[index];
		if(i!=n-1)
		cout<<" ";
	}
}