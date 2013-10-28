#include"stdio.h"
#include"string.h"
void run()
{
	char*table[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char a[102];
	scanf("%s",a);
	int sum=0;
	for(int i=0;i<strlen(a);i++)
	{
		sum+=a[i]-'0';
	}
	sprintf(a,"%d",sum);
	for(int i=0;i<strlen(a);i++)
	{
		printf("%s",table[a[i]-'0']);
		if(i!=strlen(a)-1)
			printf(" ");
	}
}
int main()
{
	//freopen("d:\\input.txt","r",stdin);
	run();
	return 0;
}
