// Tail recursion
#include <iostream>

int findSum (int pFindSumTillThis, int pResult) {

	if (pFindSumTillThis == 1)
		return pResult + 1;

	return findSum(pFindSumTillThis - 1, pResult + pFindSumTillThis);
}

int main () {

	int n;

	std::cin >> n;

	std::cout << findSum(n, 0);

	return 0;
}