#include"stdio.h"
void run()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	sum=n*5;
	int th,la;
	la=0;
	for(int i=0;i<n;i++)
	{
		
		scanf("%d",&th);
		if(th<la)
			sum+=4*(la-th);
		else
			sum+=6*(th-la);
		la=th;

	}
	printf("%d",sum);
}
int main()
{
	//freopen("d:\\input.txt","r",stdin);
	run();
	return 0;
}
