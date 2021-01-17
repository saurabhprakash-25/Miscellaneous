#include <iostream>
#include <string>

void towerOfHanoi (int pNumberOfDisks, std::string pSource, std::string pAuxiliary, std::string pDestination) {

	if (pNumberOfDisks > 0) {

		towerOfHanoi(pNumberOfDisks - 1, pSource, pDestination, pAuxiliary);

		std::cout << "Moving disk " << pNumberOfDisks << " from " << pSource << " to " << pDestination << "\n";

		towerOfHanoi(pNumberOfDisks - 1, pAuxiliary, pSource, pDestination);

	}
}

int main() {

	int no_of_disks;

	std::cin >> no_of_disks;

	towerOfHanoi (no_of_disks, "A", "C", "B");

	return 0;
}