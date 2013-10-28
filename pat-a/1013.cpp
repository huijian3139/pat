#include"iostream"
#include"vector"
#define for1(n) for(int i=0;i<n;i++)
#define for2(n) for(int j=0;j<n;j++)
#define for12(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
int getFirst0(int cc[],int N,int t)
{
	for1(N)
	{
		if(i==t)
			continue;
		if(cc[i]==0)
			return i;
	}
	return -1;
}
int getConnected(int a[][1000],int N,int t)
{
	vector<int> q;
	int cc[N];
	int count=0;
	int index;
	for1(N)
	{
		cc[i]=0;
	}
	
	while(true)
	{
		index=getFirst0(cc,N,t);
		if(index==-1)
			break;
		
		count++;
		
		q.clear();
		q.push_back(index);
		cc[index]=1;
		while(!q.empty())
		{
			int tt=q[q.size()-1];
			q.pop_back();
			for(int i=index+1;i<N;i++)
			{
				if(i==t)
				continue;
				if(a[tt][i]==1)
				{
					if(cc[i]==0)
					{
						q.push_back(i);
						cc[i]=1;
					}
				}
			}
		}
	}
	return count;
}

int a[1000][1000];
int main()
{
	
	int N,M,K;
	cin>>N>>M>>K;

	for1(M)
	{
		int t1,t2;
		cin>>t1>>t2;
		a[t1-1][t2-1]=a[t2-1][t1-1]=1;
	}
	for1(K)
	{
		int tmp;
		cin>>tmp;
		cout<<getConnected(a,N,tmp-1)-1<<endl;
	}
	return 0;
}



