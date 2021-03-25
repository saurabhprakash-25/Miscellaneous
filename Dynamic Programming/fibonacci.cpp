#include <iostream>
#include <vector>
using namespace std;

long long FindFibonacci(int pNum, vector<long long> & pMemo) {

	if (pNum == 0)
		return 0;

	if (pNum == 1)
		return 1;

	if (pMemo[pNum - 1])
		return pMemo[pNum - 1];

	pMemo[pNum -1] = FindFibonacci(pNum - 1, pMemo) + FindFibonacci(pNum - 2, pMemo);

	return pMemo[pNum - 1];
}

int main()
{
	int				    n;

    cout << "Which fibonacci number do you want me to find ? : ";
	cin >> n;

    vector<long long>   memo(n, 0);

	cout << FindFibonacci(n, memo);

	return 0;
}