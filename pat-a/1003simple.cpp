#include"stdio.h"
#include"vector"
int MAX=999999;
using namespace std;
class Point
{
	public:
		int value;
		int rescue;
		int maxrescue;
		Point()
		{
			value=MAX;
			maxrescue=0;
		}
};
int main()
{
   // freopen("d:\\input.txt","r",stdin);
	//input
	int N,M,C1,C2;
	scanf("%d %d %d %d",&N,&M,&C1,&C2);
	Point graph[N];
	int roadmap[N][N];

	for(int i=0;i<N;i++)
		scanf("%d",&graph[i].rescue);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			roadmap[i][j]=MAX+1;// +1
	for(int i=0;i<M;i++)
	{
		int c1,c2,len;
		scanf("%d %d %d",&c1,&c2,&len);
		roadmap[c2][c1]=roadmap[c1][c2]=len;
	}
	//calculate
	int count=1;// count=0 -> wa
	vector<int> queue;
	graph[C1].value=0;//value=0 -> wa
	graph[C1].maxrescue=graph[C1].rescue;
	queue.push_back(C1);
	while(!queue.empty())
	{
		int tmp=queue.back();
		queue.pop_back();
		if(tmp==C2)
			continue;
		for(int i=0;i<N;i++)
		{

			int newv=graph[tmp].value+roadmap[tmp][i];
			int newmm=graph[tmp].maxrescue+graph[i].rescue;
			if(newv==graph[i].value)
			{
				queue.push_back(i);
				if(newmm>graph[i].maxrescue)
					graph[i].maxrescue=newmm;
				if(i==C2)
					count++;
			}
			else if(newv<graph[i].value)
			{
				graph[i].value=newv;
				graph[i].maxrescue=newmm;
				queue.push_back(i);
				if(i==C2)
					count=1;
			}
		}
	}
	printf("%d %d",count,graph[C2].maxrescue);
	return 0;
}
