#include"iostream" 
using namespace std;
string earth2mar(int input)
{
	string re;
	int a=0,b=0;
	while(input>12)
	{
		input-=13;
		a++;
	}
	b=input;
	char c1,c2;
	if(a>9)
	c1=a-10+'A';
	else
	c1=a+'0';
	if(b>9)
	c2=b-10+'A';
	else
	c2=b+'0';
	re=c1;
	re+=c2;
	return re;
}
int main()
{
	int a,b,c;
	//cout<<s+"asdf";
//	earth2mar(5);
	cin>>a>>b>>c;
	cout<<'#'<<earth2mar(a)+earth2mar(b)+earth2mar(c);	
}
