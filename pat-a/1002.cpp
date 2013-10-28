#include"stdio.h"
#include"string.h"
int main()
{
	double a[1001];
	double b[1001];
	for (int i=0;i<1001;i++)
	{
		a[i]=b[i]=0;
	}
	int t1,t2;
	double t3;
	scanf("%d",&t1);
	for(int i=0;i<t1;i++)
	{
		scanf("%d",&t2);
		scanf("%lf",&t3);
		a[t2]=t3;
	}

	scanf("%d",&t1);
	for(int i=0;i<t1;i++)
	{
		scanf("%d",&t2);
		scanf("%lf",&t3);
		b[t2]=t3;
	}
	int n=0;
	for(int i=0;i<1001;i++)
	{
		a[i]=a[i]+b[i];
		if(a[i]!=0)
			n++;
	}
	printf("%d",n);
	for(int i=1000;i>=0;i--)
	{
		if(a[i]!=0)
			printf(" %d %0.1lf",i,a[i]);
	}
}

