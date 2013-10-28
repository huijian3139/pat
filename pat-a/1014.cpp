#include"iostream"
#include"vector"
#include"deque"
#include"algorithm"
#include"string"
#include"sstream"
using namespace std;

//本题容易出错的地方：是在17:00及以后开始服务的客户输出"Sorry"，而不是17:00之前结束服务的输出"Sorry"；
//如客户cId是16:59开始服务，服务时间为2，则输出的应该是17:01，而不是"Sorry"。

class Customer
{
	public:
	int id;
	int period;
	int last;
	int finish_time;
};
class Window
{
	public:
	deque<Customer> vc;
};
class Bank
{
	public:
	int systemtime;
	int M;
	int first_time;
	vector<Window> vw;
	deque<Customer> queue;
	deque<Customer> finished;
	Bank(int N,int M)
	{
		first_time=1;
		systemtime=0;
		this->M=M;
		for(int i=0;i<N;i++)
		{
			vw.push_back(Window());
		}
	}
	int allin()
	{
		for(int i=0;i<M;i++)
		{
			in();
		}
	}
	void in()
	{
		for(int i=0;i<vw.size();i++)
		{
			if(queue.empty())
				return;
			
			if(vw[i].vc.size()<M)
			{
				vw[i].vc.push_back(queue[0]);
				queue.pop_front();
			}
		}
	}
	int out()
	{
		//get the quickest customer
		int mini=-1;
		for(int i=0;i<vw.size();i++)
		{
			if(vw[i].vc.size()>0)
			{
				if(mini==-1)
					mini=vw[i].vc[0].last;
				else if(mini>vw[i].vc[0].last)
					mini=vw[i].vc[0].last;
			}
		}
		//move time
		systemtime+=mini;
		//finish task
		if(mini==-1)
			return false;
		for(int i=0;i<vw.size();i++)
		{
			if(vw[i].vc.size()>0)
			{
				vw[i].vc[0].last-=mini;
				if(vw[i].vc[0].last==0)
				{
					vw[i].vc[0].finish_time=systemtime;
					finished.push_back(vw[i].vc[0]);
					vw[i].vc.pop_front();
				}
			}
		}
		return true;
	}
	int proceed()
	{
		if(first_time)
		{
			allin();
			first_time=0;
		}
		else
			in();
		return out();
	}
	string query(int q)
	{
		stringstream ss;
		int t=finished[q-1].finish_time;
		if((t-finished[q-1].period)>=9*60)
			ss<<"Sorry";
		else
		{
			ss.fill('0');
			ss.width(2);
			ss<<t/60+8;
			ss<<":";
			ss.fill('0');
			ss.width(2);
			ss<<t%60;	
		}	
		return ss.str();
	}
};
bool comp(const Customer&c1,const Customer&c2)
{
	return c1.id<c2.id;
}
void run()
{
	int N,M,K,Q;
	cin>>N>>M>>K>>Q;
	
	Bank bank(N,M);
	for(int i=0;i<K;i++)
	{
		Customer c;
		cin>>c.period;
		c.last=c.period;
		c.id=i+1;
		bank.queue.push_back(c);
	}
	
	while(bank.proceed())
	{
	}
	sort(bank.finished.begin(),bank.finished.end(),comp);
	for(int i=0;i<Q;i++)
	{
		int q;
		cin>>q;
		cout<<bank.query(q)<<endl;
	}
	
}
int main()
{
	//freopen("d:\\input.txt","r",stdin);
	run();
	return 0;
}
