#include"stdio.h"
#include"string.h"
using namespace std;
void run()
{
	int N;
	scanf("%d",&N);
	char a[N][16];
	int signin[N];
	int signout[N];
	for(int i=0;i<N;i++)
	{
		int hour,min,sec;
		scanf("%s",&a[i][0]);
		scanf("%d:%d:%d",&hour,&min,&sec);
		signin[i]=hour*3600+min*60+sec;
		scanf("%d:%d:%d",&hour,&min,&sec);
		signout[i]=hour*3600+min*60+sec;
	}
	int MIN=24*3600;
	int MAX=-1;
	int iMIN,iMAX;
	for(int i=0;i<N;i++)
	{
		if(signin[i]<MIN)
		{
			MIN=signin[i];
			iMIN=i;
		}
		if(signout[i]>MAX)
		{
			MAX=signout[i];
			iMAX=i;
		}
	}
	printf("%s %s",&a[iMIN][0],&a[iMAX][0]);
}
int main()
{
//	freopen("d:\\input.txt","r",stdin);
	run();
	return 0;
}
