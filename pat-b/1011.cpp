#include"iostream"
#include"string"
using namespace std;
 int main()
 {
 	int t;
 	cin>>t;
 	
 	for(int i=0;i<t;i++)
 	{
	 	int a,b,c;
	 	string re="";
	 	cin>>a>>b>>c;


 		if((a>0)&&(b>0))
 		{
	 		if((a+b)<a)
	 		re="true";
	 	}
	 	else if((a<0)&&(b<0))
	 	{
 			if((a+b)>a)
 			re="false";
 		}
 		
	 	if(re==""){
		 	if((a+b)>c)
	 		re="true";
	 		else
	 		re="false";
	 	}

	 	
	 	cout<<"Case #"<<i+1<<": "<<re<<endl;
	 }
 	return 0;
 }
 