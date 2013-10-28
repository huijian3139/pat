#include "iostream"
#include <cmath>
using namespace std;
bool is_prime(int x) {
	if(x<=1)
		return false;
	for(int i=2;i<=sqrt(x);++i) {
		if(x%i==0) return false;
	}
	return true;
}
int main()
{

	int N,D;
	int f=1;
	while(cin>>N>>D && N>=0)
	{
		int s = 0;
		int t=N;
		while(N) {
			s = s*D + N%D;
			N /= D;
		}
		cout<<((is_prime(t)&&is_prime(s))?"Yes":"No")<<endl;
	}
	return 0;
}
