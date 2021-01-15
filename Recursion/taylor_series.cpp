#include<iostream>

double taylor(int x, int n, double pResult) {

	if (n == 0)
		return pResult;

	pResult = 1 + ((x * pResult) / n);

	return taylor(x, n - 1, pResult);
}

int main() {

	int x, n;

	std::cin >> x;
	std::cin >> n;

	std::cout << taylor(x, n, 1);

	return 0;
}