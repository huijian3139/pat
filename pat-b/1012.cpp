#include"iostream"
#include"stdio.h"
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a1,a2,a3,a4,a5;
	a1=a2=a3=a4=a5=0;
	int a2c=1;
	int a2o=0;
	int na4=0;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		if(t%10==0)
			a1+=t;
		if(t%5==1)
		{
			a2o=1;
			a2+=t*a2c;
			a2c=-a2c;
		}
		if(t%5==2)
		{
			a3++;
		}
		if(t%5==3)
		{
			a4+=t;
			na4++;
		}
		if(t%5==4)
		{
			if(a5<t)
				a5=t;
		}


	}
	double d4;
	if(na4!=0)
		d4=1.0*a4/na4;
	if(a1==0)
		cout<<"N ";
	else 
		cout<<a1<<" ";
	if(a2o==0)
		cout<<"N ";
	else
		cout<<a2<<" ";
	if(a3==0)cout<<"N ";
	else cout<<a3<<" ";
	if(na4!=0)
	cout<<fixed<<setprecision(1)<<d4<<" ";
	else
		cout<<"N ";
	if(a5==0)
		cout<<"N";
	else 
		cout<<a5;
	return 0;

}