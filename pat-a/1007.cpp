#include"stdio.h"
void run()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int allne=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		if(a[i]>=0)
			allne=0;
	}
	if(allne)
	{
		printf("%d %d %d",0,a[0],a[n-1]);
		return;
	}

	int MAX=-1;
	int iMAX1,iMAX2;
	int i1=0;
	int sum=0;
	
	for(int i2=0;i2<n;i2++)
	{
		sum+=a[i2];
		// the two "if" can not be exchanged, otherwise wa!
		if(sum>MAX)
		{
			MAX=sum;
			iMAX1=i1;
			iMAX2=i2;
		}
		if(sum<0)
		{
			sum=0;
			i1=i2+1;
		}

	}

	printf("%d %d %d",MAX,a[iMAX1],a[iMAX2]);

}
int main()
{
//	freopen("d:\\input.txt","r",stdin);
	run();
	return 0;
}
