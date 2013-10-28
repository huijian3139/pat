#include"iostream"
using namespace std;
int dd[3000];
int getDD(int index)
{
	return dd[index+1500];
}
int addDD(int index,int input)
{
	dd[index+1500]+=input;
}
int main()
{
//freopen("d:\\input.txt","r",stdin);
	int a,b;int c=0;
	while(cin>>a>>b)
	{
		addDD(b,a);
	}
	for(int i=1200;i>=-1200;i--)
	{
		int tmp=getDD(i);
		if((tmp!=0)&&(i!=0))
		{
			if(c!=0)
				cout<<" ";
			else
				c=1;
			cout<<tmp*i<<" "<<i-1;
		}
	}if(c==0)
	cout<<"0 0";
	return 0;
}