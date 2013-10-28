#include"stdio.h"
#include"string.h"
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int c;
    c=a+b;
    if(c<0)
    {
        printf("-");
        c=-c;
    }
    char tmp[100];
    sprintf(tmp,"%d",c);
    for(int i=0;i<strlen(tmp);i++)
	{
		if((strlen(tmp)-i)%3==0)
		{
			if(i!=0)
			{
				printf(",");
			}
		}
		printf("%c",tmp[i]);
	}
    return 0;
	
}
