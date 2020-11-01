#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int N,PrimeIndex=2;
	cin>>N;
	int Primes[N];
	Primes[0]=2;
	Primes[1]=3;
	for(int p=5;p<N;p+=2)
	{
		for(int i=0;i<PrimeIndex&&Primes[PrimeIndex-1]<=sqrt(N);i++)
		{
			if(p%Primes[i]==0)
				break;
		}
		Primes[PrimeIndex]=p;
		PrimeIndex++;
	}
	cout<<endl;
	for(int i=0;i<PrimeIndex;i++)
		cout<<Primes[i]<<" ";
	cout<<endl;
	return 0;
}