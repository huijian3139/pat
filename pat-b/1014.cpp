#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
char *zhou[]={
	"MON","TUE","WED","THU","FRI","SAT","SUN"
};
int main()
{
	//freopen("d:\\input.txt","r",stdin);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int minlen=s1.length()>s2.length()?s2.length():s1.length();
	int i;
	for(i=0;i<minlen;i++)
	{
		if(s1[i]==s2[i])
		{
			if(('A'<=s1[i])&&(s1[i]<='G'))
			{
				cout<<zhou[s1[i]-'A']<<" ";
				break;
			}
		}
	}
	i++;
	cout.fill('0');
	cout.width(2);
	for(;i<minlen;i++)
	{
		if(s1[i]==s2[i])
		{
			
			if((s1[i]>='0')&&(s1[i]<='9'))
			{
				cout<<s1[i]-'0';
				break;
			}
			if((s1[i]>='A')&&(s1[i]<='N'))
			{
				cout<<s1[i]-'A'+10;
				break;
			}
		}
	}
	
	cout<<":";
	minlen=s3.length()>s4.length()?s4.length():s3.length();
	for(i=0;i<minlen;i++)
	{
		if(s3[i]==s4[i])
		{
			if(((s3[i]>='a')&&(s3[i]<='z'))||((s3[i]>='A')&&(s3[i]<='Z')))
			{
				cout.fill('0');
				cout.width(2);
				cout<<i;
				break;
			}
			
		}
	}
	return 0;
}
