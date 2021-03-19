#include <iostream>
using namespace std;

long long FindFibonacci(int pNum, long long * pSol) {

	if (pNum == 0)
		return 0;

	if (pNum == 1)
		return 1;

	if (pSol[pNum])
		return pSol[pNum];

	pSol[pNum] = FindFibonacci(pNum - 1, pSol) + FindFibonacci(pNum - 2, pSol);

	return pSol[pNum];
}

int main()
{
	int				n;
	long long *		sol;

	cout << "Which fibonacci number do you want me to find ? : ";
	cin >> n;

	sol = new long long[n+1]();

	cout << FindFibonacci(n, sol);

	return 0;
}