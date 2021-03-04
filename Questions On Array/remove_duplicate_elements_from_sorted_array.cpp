#include <iostream>
#include<vector>
using namespace std;

vector<int> RemoveDuplicatesFromArray (vector<int> pArray)
{
        int pos = 0;

    for (int i = 0; i < pArray.size () - 1; ++i) {

        if (pArray[i] != pArray[i+1]) {

            pArray[pos]= pArray[i];
            ++pos;
        }
    }

    // Insert the last element
    pArray[pos] = pArray[pArray.size () - 1];

    pArray.erase (pArray.begin() + pos + 1, pArray.end ());

    return pArray;
}

int main ()
{
        int         value;
        vector<int> array;

    // Take the input
    cout<<"Enter the elements of the array. When done, enter d : ";
    while (cin >> value) {

        array.push_back (value);
    }

    // Print the array without duplicate elements
    cout<<"The array without duplicates is : ";
    for (auto i : RemoveDuplicatesFromArray (array)){
        cout << i <<" ";
    }

    cout << "\n";

    return 0;
}