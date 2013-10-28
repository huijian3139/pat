#include"iostream"
#include"vector"
#include"deque"
#include"algorithm"
#include"string"
#include"sstream"
#include"stdio.h"
#include"string.h"
using namespace std;


void run()
{
	int N,K;
	cin>>N>>K;
	vector<int> vi;
	do
	{
		vi.push_back(N%K);
		N/=K;
	}
	while(N);
	int ret=0;
	for(int i=0;i<vi.size()-i-1;i++)
	{
		if(vi[i]!=vi[vi.size()-i-1])
		{
			ret=1;
			break;
		}
	}
	if(ret)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	for(int i=vi.size()-1;i>=0;i--)
	{
		cout<<vi[i];
		if(i!=0)
			cout<<" ";
	}
}
void local_test()
{
	system("notepad d:\\input.txt");
	freopen("d:\\input.txt","r",stdin);
}
int main()
{
	//local_test();
	run();
	return 0;
}
