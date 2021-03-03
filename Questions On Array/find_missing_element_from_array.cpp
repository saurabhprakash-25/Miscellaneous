#include <iostream>
#include <vector>
using namespace std;

int gRangeStart;
int gRangeEnd;

using FindMissingElementFunc = vector<int>(*)(vector<int>);

int FindMissingElementsXOR (vector<int> pArray)
{
        int allxor = gRangeStart;
        int arrxor = pArray[0];

    for (int i = gRangeStart + 1; i <= gRangeEnd; ++i ) {

        allxor = (allxor ^ i);
    }

    for (int i = 1; i < pArray.size (); ++i) {

        arrxor = (arrxor ^ pArray[i]);
    }

    return (allxor ^ arrxor);
}

/**
 * @brief Finds the only missing element from the array
 *
 * @param pArray
 * @return vector<int>
 */
vector<int> FindMissingElement (vector<int> pArray)
{
        vector<int> res;

    // Since there's only one elements, the xor would be same as the missing elemet
    res.push_back (FindMissingElementsXOR (pArray));

    return res;
}

/**
 * @brief Finds exactly 2 missing elements from the array
 *
 * @param pArray
 * @return vector<int>
 */
vector<int> FindTwoMissingElements (vector<int> pArray)
{
        int         num_xor;
        int         set_bit;
        int         set_num = 0;
        int         unset_num = 0;
        vector<int> res;

    // Find the xor of the 2 missing elements
    num_xor = FindMissingElementsXOR (pArray);

    // Find the rightmost set bit of the this number. This would mean that one of the missing numbers
    // has this bit set while the other one has it unset
    set_bit = num_xor ^ (num_xor & (num_xor - 1));

    // Now find xor of all the elements that have this rightmost bit set and unset seperately
    for (auto i : pArray) {

        if (i & set_bit) {

            set_num = (set_num ^ i);

        } else {

            unset_num = (unset_num ^ i);
        }
    }

    // Xor the two numbers obtained from different sets with all the numbers present in the given
    // range in that set. This would give us the missing numbers.
    for (int i = gRangeStart; i <= gRangeEnd; ++i) {

        if (i & set_bit) {

            set_num =  (set_num ^ i);

        } else {

            unset_num = (unset_num ^ i);
        }
    }

    res.push_back (set_num);
    res.push_back (unset_num);

    return res;
}

int main ()
{
        int                     no_of_missing_elements = 0;
        vector<int>             array;
        FindMissingElementFunc  func;

    cout << "Enter the range (a to b) : ";
    cin >> gRangeStart >> gRangeEnd;

    cout << "Enter the number of missing elements : ";
    cin >> no_of_missing_elements;

    cout << "Ente rthe elements : ";
    for (int i = gRangeStart; i <= gRangeEnd - no_of_missing_elements; ++i) {
            int value;

        cin >> value;
        array.push_back (value);
    }

    if (no_of_missing_elements == 1) {

        func = FindMissingElement;

    } else {

        func = FindTwoMissingElements;
    }

    cout << "The missing elements are :";
    for (auto i : func (array)) {

        cout << i << " ";
    }
    return 0;
}