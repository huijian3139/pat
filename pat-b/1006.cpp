#include"iostream"
#include"string"
using namespace std;
void printB(int a)
{
	for(int i=0;i<a;i++)
	cout<<"B";
}
void printS(int a)
{
	for(int i=0;i<a;i++)
	cout<<"S";
}
void printG(int a)
{
	for(int i=0;i<a;i++)
	cout<<i+1;
}
int main()
{
	string s;
	cin>>s;
	if(s.length()==3)
	{
		printB(s[0]-'0');
		printS(s[1]-'0');
		printG(s[2]-'0');
	}
	else if(s.length()==2)
	{	
		printS(s[0]-'0');
		printG(s[1]-'0');
	}
	else
	{
		printG(s[0]-'0');
	}
	return 0;
}