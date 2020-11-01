// Problem : Given 2 sorted arrays, find the elements that are common
// Array, Seacrching, HashMap

#include <unordered_map>
#include <vector>
#include <iostream>

void CreateHashTableFromArray(std::vector<int> pArray, std::unordered_map<int, char> & pHashTable)
{
	for (auto itr : pArray) {

		pHashTable[itr] = 'a';
	}
}

// ! This algorithm solves the given problem in O (n) time with O(n) space complexity
std::vector<int> FindCommonElements(std::vector<int> pFirstArray, std::vector<int> pSecondArray)
{
	std::unordered_map <int, char> hash_table;
	std::vector<int>    result;

	CreateHashTableFromArray(pSecondArray, hash_table);

	for (auto itr : pFirstArray) {

		if (hash_table[itr] == 'a') {

			result.push_back(itr);
		}
	}

	return result;
}

int main()
{
	std::vector<int> first_array{ 13,27,35,40,49,55,59 };
	std::vector<int> second_array{ 17,35,39,40,55,58,60 };

	for (auto itr : FindCommonElements (first_array, second_array)) {

		std::cout << itr << " ";
	}

	return 0;
}