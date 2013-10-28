#include"stdio.h"
#include"string.h"
char*tt[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
int main()
{
	char a[105];
	int sum=0;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
	{
		sum+=a[i]-'0';
	}
	sprintf(a,"%d",sum);
	for(int i=0;i<strlen(a);i++)
	{
		printf("%s",tt[a[i]-'0']);
		if(i!=(strlen(a)-1))
		printf(" ");
		
	}
}
