#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stdio.h"
#include <sstream>
using namespace std;
int calmoney(int startd,int starth,int startm,int endd,int endh,int endm,int*charge,int *time)
//cent money
{
	*time=0;
	int money=0;
	int daymoney=0,hourmoney=0,minutemoney=0;
	for(int i=0;i<24;i++)
	{
		daymoney+=charge[i];
	}
	daymoney*=60;
	//calculate day
	daymoney*=(endd-startd-1);
	*time=(endd-startd-1)*60*24;
	money+=daymoney;
	//h:m - 24:00
	for(int i=starth+1;i<=23;i++)
	{
		hourmoney+=charge[i];
	}
	hourmoney*=60;
	minutemoney=(60-startm)*charge[starth];
	money+=hourmoney;
	money+=minutemoney;
	*time+=(24-starth)*60-startm;
	//00:00 - endh:endm
	hourmoney=0;
	for(int i=0;i<endh;i++)
	{
		hourmoney+=charge[i];
	}
	hourmoney*=60;
	minutemoney=charge[endh]*(endm);
	money+=hourmoney;
	money+=minutemoney;
	*time+=endh*60+endm;
	return money;
}

struct rec
{
	string key;
	int d,h,m;
	int op;
	/* data */
};
bool comp(const rec &a,const rec &b)
{
	//cout<<a.key<<" "<<b.key<<" ";
	if(a.key<b.key)
	{	
		//cout<<-1<<endl;
		return 1;
	}
	else if(a.key>b.key)
	{
		return 0;
	}
	else
	{//cout<<0<<endl;
		int aa=a.m+a.h*60+a.d*60*24;
		int bb=b.m+b.h*60+b.d*60*24;
		if(aa<bb)
			return 1;
		else
			return 0;
	}
}
int main()
{
	vector<string> vs;
	vector<int> bm;

	string name,opt;
	int mon,day,hour,minute;
	////
	char c;
	vector<rec> v;
	int charge[24];
	int N;
	
	for(int i=0;i<24;i++)
		cin>>charge[i];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		rec t;
		cin>>name>>mon>>c>>day>>c>>hour>>c>>minute>>opt;
		if((opt=="on-line")||(opt=="off-line"))
			;
		else continue;
		char tmp[4];
		sprintf(tmp,"%02d",mon);
		t.key=name+" "+tmp;
		t.d=day;
		t.h=hour;
		t.m=minute;
		t.op=((opt=="on-line")?1:0);
		v.push_back(t);
	}
	sort(v.begin(),v.end(),comp);
	string nown="";
	int money=0;
	int state=0;//1:half pair
	int startd;
	int starth;
	int startm;
	for(int i=0;i<v.size();i++)
	{
		//cout<<v[i].key<<" "<<v[i].d<<" "<<v[i].h<<" "<<v[i].m<<" "<<v[i].op<<endl;
		if(nown!=v[i].key)
		{
			if(i!=0)
			{
				char tmp[500];
				sprintf(tmp,"Total amount: $%0.2lf\n", (double)money/100);
				vs[vs.size()-1]+=tmp;
				bm.push_back(money);
			}	//
			nown=v[i].key;
			vs.push_back(nown+"\n");
			money=0;
			state=0;
		}
		if(state==0)
		{
			if(v[i].op==1)
			{
				state=1;
				startd=v[i].d;
				starth=v[i].h;
				startm=v[i].m;
			}
		}
		else
		{
			if(v[i].op==1)
			{
				startd=v[i].d;
				starth=v[i].h;
				startm=v[i].m;
			}
			else
			{
				int endd=v[i].d;
				int endh=v[i].h;
				int endm=v[i].m;
				int thismoney=0;
				int time=0;
				thismoney=calmoney(startd,starth,startm,endd,endh,endm,charge,&time);
				char tmp[500];
				sprintf(tmp,"%02d:%02d:%02d %02d:%02d:%02d %d $%0.2lf\n",startd,starth,startm,endd,endh,endm,time,(double)thismoney/100);
				vs[vs.size()-1]+=tmp;
				money+=thismoney;
			}
		}
	}
	char tmp[500];
	sprintf(tmp,"Total amount: $%0.2lf\n", (double)money/100);
	bm.push_back(money);
	vs[vs.size()-1]+=tmp;
	for(int i=0;i<vs.size();i++)
	{
		if(bm[i])
			cout<<vs[i];
	}
	return 0;
}
