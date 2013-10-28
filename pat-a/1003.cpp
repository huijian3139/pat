#include"stdio.h"
#include"string.h"
#include"vector"
using namespace std;
class Point
{
	public:
		int value;
		vector<int> list;
		Point()
		{
			value=-1;
		}
};
int main()
{
   // freopen("d:\\input.txt","r",stdin);
	//input
	int N,M,C1,C2;
	scanf("%d %d %d %d",&N,&M,&C1,&C2);
	int city[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&city[i]);
	}
	int roadmap[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			roadmap[i][j]=-1;
		}
	}
	for(int i=0;i<M;i++)
	{
		int c1,c2,len;
		scanf("%d %d %d",&c1,&c2,&len);
		roadmap[c2][c1]=roadmap[c1][c2]=len;

	}
	//calculate
	Point graph[N];
	vector<int> queue;
	graph[C1].value=0;
	queue.push_back(C1);
	while(!queue.empty())
	{
		int tmp=queue.back();
		queue.pop_back();
		graph[tmp];
		for(int i=0;i<N;i++)
		{
			if(roadmap[tmp][i]!=-1)
			{
				if(graph[i].value==-1)
				{
					graph[i].value=graph[tmp].value+roadmap[tmp][i];
					graph[i].list.push_back(tmp);
					queue.push_back(i);
				}
				else
				{
					int newv=graph[tmp].value+roadmap[tmp][i];
					if(newv==graph[i].value)
					{
						int re=0;
						for(int j=0;j<graph[i].list.size();j++)
						{
							
							if(graph[i].list[j]==tmp)
							{
								re=1;
							}
						}
						if(re==0)
							graph[i].list.push_back(tmp);
					}
					else if(newv<graph[i].value)
					{
						graph[i].value=newv;
						graph[i].list.clear();
						graph[i].list.push_back(tmp);

						queue.push_back(i);
					}
				}
			}
		}
	}
	int count=0;
	queue.clear();
	queue.push_back(C2);
	int wage[N];
	for(int i=0;i<N;i++)
		wage[i]=0;
	wage[C2]=city[C2];
	while(!queue.empty())
	{
		
		int tmp;
		tmp=queue.back();
		queue.pop_back();
		if(tmp==C1)
			count++;
		for(int i=0;i<graph[tmp].list.size();i++)
		{
			int t=graph[tmp].list[i];
			int newvv=wage[tmp]+city[t];
			if(wage[t]<newvv)
				wage[t]=newvv;
			queue.push_back(t);
		}

	}
	printf("%d %d",count,wage[C1]);
	return 0;

}

