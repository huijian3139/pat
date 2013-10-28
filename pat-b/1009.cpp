#include"iostream"
#include"vector"
#include"string"
#include"sstream"
using namespace std;
int main()
{
	vector<string> vs;
	string s;
	char a[100];
	cin.getline(a,100);
	stringstream ss(a);
	while(ss>>s)
	{
		vs.push_back(s);
	}
	for(int i=vs.size()-1;i>=0;i--)
	{if(i!=vs.size()-1)cout<<" ";
		cout<<vs[i];
	}
	return 0;
}