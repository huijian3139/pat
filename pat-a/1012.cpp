#include"iostream"
#include"string"
#include"algorithm"
#include "vector"
using namespace std;
class stu{
	public:
		int id,c1,c2,c3,c4;
		void go()
		{
			c4=(c1+c2+c3)/3;
		}
};


int mini(int a,int b,int c, int d)
{
	int m=a;
	if(m>b)
	m=b;
	if(m>c)
	m=c;
	if(m>d)
	m=d;
	return m;
}
int main()
{//freopen("d:\\input.txt","r",stdin);
	int N,M;
	cin>>N>>M;
	stu qq[N];
	for(int i=0;i<N;i++)
	{
		cin>>qq[i].id>>qq[i].c1>>qq[i].c2>>qq[i].c3;
		qq[i].go();
	}
	for(int ii=0;ii<M;ii++)
	{
		int query;
		cin>>query;
		int match=0;
		int i;
		for(i=0;i<N;i++){
			if(query==qq[i].id)
			{
				match=1;
				break;
			}
		}
		if(match==1)
		{
			int t=i;
			int count1=1;
			int count2=1;
			int count3=1;
			int count4=1;
			for(i=0;i<N;i++){
				if(qq[i].c1>qq[t].c1)
				{
					count1++;
				}
				if(qq[i].c2>qq[t].c2)
				{
					count2++;
				}
				if(qq[i].c3>qq[t].c3)
				{
					count3++;
				}
				if(qq[i].c4>qq[t].c4)
				{
					count4++;
				}
			}
			int m=mini(count1,count2,count3,count4);
			cout<<m<<" ";
			if(count4==m)
			{
				cout<<"A";
			}
			else if(count1==m){
				cout<<"C";
			}
			else if(count2==m){
				cout<<"M";
			}
			else if(count3==m)
			{
				cout<<"E";
			}
		}
		else
		cout<<"N/A";
		if(ii!=M-1)
		cout<<endl;
	}
}







