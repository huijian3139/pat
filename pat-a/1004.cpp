#include"stdio.h"
#include"vector"
using namespace std;
int N,M;
int a[100][100];
vector<int> queue;
int hasChild(int input)
{
	for(int i=0;i<100;i++)
	{
		if(a[input][i]==1)
			return 1;
	}
	return 0;
}
int main()
{
	//freopen("d:\\input.txt","r",stdin);	
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			a[i][j]=0;

	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int K,node;
		scanf("%d %d",&node,&K);
		for(int j=0;j<K;j++)
		{
			int t;
			scanf("%d",&t);
			a[node][t]=1;
		}
	}
	queue.push_back(01);
	while(queue.size()!=0)// each level
	{
		int count=0;
		for(int i=0;i<queue.size();i++)
		{
			if(!hasChild(queue[i]))
				count++;
		}
		vector<int> tmp;
		for(int i=0;i<queue.size();i++)
		{
			int k=queue[i];
			for(int j=0;j<100;j++)
			{
				if(a[k][j]==1)
					tmp.push_back(j);
			}
		}
		queue=tmp;
		if(queue.size()!=0)
			printf("%d ",count);
		else
			printf("%d",count);
	}
	return 0;
}

