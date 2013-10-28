#include"vector"
#include"algorithm"
#include"stdio.h"
#include"string.h"
using namespace std;
struct stu
{
	int id;
	int de;
	int cai;
	int type;
};
bool comp(const stu&s1,const stu&s2)
{
	if(s1.type!=s2.type)
		return s1.type>s2.type;
	else if((s1.de+s1.cai)!=(s2.de+s2.cai))
		return (s1.de+s1.cai)>(s2.de+s2.cai);
	else if(s1.de!=s2.de)
		return s1.de>s2.de;
	else{
		return s1.id<s2.id;
	}
}
int main()
{
	//freopen("d:\\input.txt","r",stdin);
	vector<stu> vs;
	int N,L,H;
	scanf("%d %d %d",&N,&L,&H);
	//cin>>N>>L>>H;
	for(int i=0;i<N;i++)
	{
		stu tmp;
		scanf("%d%d%d",&tmp.id,&tmp.de,&tmp.cai);
		if((tmp.de>=L)&&(tmp.cai>=L))
		{
			if((tmp.de>=H)&&(tmp.cai>=H))
			{
				tmp.type=4;
			}
			else if((tmp.de>=H)&&(tmp.cai<H))
			{
				tmp.type=3;
			}
			else if((tmp.de<H)&&(tmp.de>=tmp.cai))
			{
				tmp.type=2;
			}
			else
			{
				tmp.type=1;
			}
			vs.push_back(tmp);
		}
	}
	
	sort(vs.begin(),vs.end(),comp);
	printf("%d\n",vs.size());
	//cout<<vs.size()<<endl;
	for(int i=0;i<vs.size();i++)
	{
		printf("%08d %d %d\n",vs[i].id,vs[i].de,vs[i].cai);
	}
	return 0;
}
