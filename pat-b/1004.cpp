#include"iostream"
#include"string"
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string name[n];
	string id[n];
	int sc[n];
	int small=101,big=-1;
	int ismall,ibig;
	for(int i=0;i<n;i++)
	{
		cin>>name[i];
		cin>>id[i];
		cin>>sc[i];
		if(sc[i]>big)
		{
			big=sc[i];
			ibig=i;
			
		}
		if(sc[i]<small)
		{
			small=sc[i];
			ismall=i;
		}
	}
	cout<<name[ibig]<<" "<<id[ibig]<<endl;
	cout<<name[ismall]<<" "<<id[ismall];
	
	
	
}
