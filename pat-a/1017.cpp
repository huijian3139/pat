#include"iostream"
#include"vector"
#include"deque"
#include"algorithm"
#include"string"
#include"sstream"
#include"stdio.h"
#include"string.h"
using namespace std;

class Customer
{
	public:
	int period;
	int arrive;
	int serve;
};
bool comp(const Customer&c1,const Customer&c2)
{
	return c1.arrive<c2.arrive;
}
class Bank
{
	public:
	vector<Customer> queue;
	int K;
	int opentime;
	int endtime;
	int curtime; 
	vector<Customer> window;
	Bank()
	{
		opentime=8*60*60;
		endtime=17*60*60;
		curtime=opentime;
	}
	int proceed()
	{
		if(window.size()==0)
		{
			
		}
		else if(window.size()==K)
		{
			
		}
		else
		{
			
		}
	}
};
void run()
{
	Bank bank;
	int N;
	cin>>N>>bank.K;
	
	for(int i=0;i<N;i++)
	{
		int h,m,s,mm;
		char c;
		cin>>h>>c>>m>>c>>s>>mm;
		Customer cus;
		cus.period=mm*60;
		cus.arrive=h*3600+m*60+s;
		if(cus.arrive<=bank.endtime)
			bank.queue.push_back(cus);
	}
	sort(bank.queue.begin(),bank.queue.end(),comp);
	while(bank.proceed())
	{
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
