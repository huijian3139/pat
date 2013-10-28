
#include"stdio.h"
void run()
{
	double a[1001]={0};
	double b[1001]={0};
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int n;
		double an;
		scanf("%d %lf",&n,&an);
		a[n]=an;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int n;
		double an;
		scanf("%d %lf",&n,&an);
		b[n]=an;
	}
	
	double c[2001]={0};
	for(int i=0;i<1001;i++)
	{	for(int j=0;j<1001;j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
	k=0;
	for(int i=0;i<2001;i++)
	{
		if(c[i]!=0)
			k++;
	}
	printf("%d",k);
	for(int i=2000;i>=0;i--)
	{
		if(c[i]!=0)
		{
			printf(" %d %0.1lf",i,c[i]);
		}
	}

}
int main()
{
	//freopen("d:\\input.txt","r",stdin);
	run();
	return 0;
}
