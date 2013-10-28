#include"iostream"
using namespace std;
void ps(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" ";
	}
}
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	int n1,n2;
	n2=(l+2)/3;
	if((n2*3)!=(l+2))
	n2++;
	while(((2+l-n2)%2)==1)
	n2++;
	n1=(l+2-n2)/2;
	for(int i=0;i<n1-1;i++)
	{
		cout<<s[i];
		ps(n2-2);
		cout<<s[l-i-1]<<endl;
	}
	for(int i=n1-1;i<n1-1+n2;i++)
	{
		cout<<s[i];
	}
	
	
	return 0;
}
