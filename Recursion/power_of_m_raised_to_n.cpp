// Uses tail recursin
#include<iostream>

long long power (int pNum, int pExponent, int pResult) {

	if (pExponent == 0)
		return pResult;

	if (pExponent == 1)
		return pResult * pNum;

	return power(pNum, pExponent - 1, pResult * pNum);
}

int main (){

	int m, n;

	std::cin>>m;
	std::cin>>n;

	std::cout<<power (m, n, 1);

	return 0;
}