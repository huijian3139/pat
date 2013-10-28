#include"iostream"
#include"string"
#include"algorithm"
#include"vector"
using namespace std;
int main()
{
	int n;cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int bitmap[n];
	for(int i=0;i<n;i++)
	bitmap[i]=1;
	for(int i=0;i<n;i++){
		if(bitmap[i]==0)continue;
		int tn=num[i];
		while(1)
		{
			if(tn==1)
			break;
			if(tn%2==0)
			tn/=2;
			else
			tn=(3*tn+1)/2;
			for(int j=0;j<n;j++)
			{if(num[j]==tn)
			bitmap[j]=0;
			}
		}
	}
	int tag=0;
	vector<int> qq;
	for(int i=0;i<n;i++)
	{
		if(bitmap[i]==1)
		{qq.push_back(num[i]);
		}
	}
	sort(qq.rbegin(),qq.rend());
	for(int i=0;i<qq.size();i++)
	{if(i!=0)cout<<" ";
	cout<<qq[i];}
}
