#include <iostream>

int fib (int pTillThis, int pTerm1 = 0, int pTerm2 = 1) {

    if (pTillThis == 0)
        return pTerm1;

    if (pTillThis == 1)
        return pTerm2;

    return fib(pTillThis - 1, pTerm2, pTerm1 + pTerm2);
}

int main () {

    int n;

    std::cin>>n;


    std::cout<<fib(n);

    return 0;
}