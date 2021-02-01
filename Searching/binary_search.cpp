#include <iostream>
#include <vector>
using namespace std;

constexpr int gNotFound = -11;

int BinarySearch(vector<int> pElementList, int pKey)
{
	int low = 0;
	int high = pElementList.size() - 1;
	int mid = 0;

	while (low <= high) {

		mid = (low + high) / 2;

		if (pElementList.at(mid) == pKey) {

			return mid;

		}
		else if (pElementList.at(mid) < pKey) {

			low = mid + 1;

		}
		else {

			high = mid - 1;
		}
	}

	// Not found
	return gNotFound;
}

int main()
{
	int              no_of_elements = 0;
	int              cur_element = 0;
	int              inputs_taken = 0;
	int              key = 0;
	int              found_pos = 0;
	std::vector<int> element_list;

	cout << "Pease enter the number of elements in the array : ";
	cin >> no_of_elements;

	cout << "Please enter the elements in sorted order : ";
	while ((++inputs_taken <= no_of_elements) && std::cin >> cur_element) {

		element_list.push_back(cur_element);
	}

	cout << "Which element do you want to search ? : ";
	cin >> key;

	if ((found_pos = BinarySearch(element_list, key)) != gNotFound) {

		cout << "Element found at position " << found_pos << "\n";

	}
	else {

		cout << "Oops! Element not found!\n";
	}

	return 0;
}