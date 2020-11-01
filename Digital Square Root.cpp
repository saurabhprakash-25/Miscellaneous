#include<iostream>
using namespace std;
int main()
{
	int N,sum;
	cout<<"Enter a number"<<endl;
	cin>>N;
	while(N>9)
	{
		sum=0;
		while(N>0)
		{
			sum+=N%10;
			N=N/10;
		}
		N=sum;
	}
	cout<<N<<endl;
	return 0;
}