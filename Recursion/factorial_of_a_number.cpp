// Uses tail recursion
#include <iostream>

long long factorial(int pFindFactorialTillThis, long long pResult) {

	if (pFindFactorialTillThis == 0)
		return pResult;

	return factorial(pFindFactorialTillThis - 1, pFindFactorialTillThis * pResult);
}

int main() {

	int n;

	std::cin >> n;

	std::cout << factorial(n, 1);

	return 0;
}