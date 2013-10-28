#include"iostream"
#include"string"
#include"algorithm"
#include"vector"
using namespace std;
int check(string s)
{
	for(int i=0;i<s.length();i++){
		if((s[i]=='P')||(s[i]=='A')||(s[i]=='T'));else
		return 0;
	}

	int parta=0;
	int partb=0;
	int partc=0;
	int state=1;
	for(int i=0;i<s.length();i++){
		if(state==1)
		{
			if(s[i]=='A')
			parta++;
			else if(s[i]=='P')
			state=2;
			else
			return 0;
		}
		else if(state==2)
		{
			if(s[i]=='A')
			partb++;
			else if(s[i]=='T')
			state=3;
			else
			return 0;
		}
		else if(state==3)
		{
			if(s[i]=='A')
			partc++;
			else
			return 0;
		}
	}
	if(partb*parta==partc)
	if(partb>=1)
	if(state==3)
	return 1;
	return 0;
	
}
int main()
{//freopen("d:\\input.txt","r",stdin);
	int n;cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{cin>>s;
	if(check(s))
	cout<<"YES";
	else
	cout<<"NO";
		if(i!=n-1)cout<<endl;
	}
	return 0;
}
