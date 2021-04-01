// Write a function "canSum (targetSum, numbers)" that takes in a targetSum and and
// array of numbers as arguments.

// The function should return a boolean indicating whether or not it is possible to
// generate the targetSum using numbers in the array
#include<iostream>
#include<vector>
using namespace std;

vector<bool>	memo;

bool canSum(int targetSum, vector<int> numbers)
{
    if (targetSum == 0)
        return true;

    if (memo[targetSum])
        return true;

    for (auto num : numbers) {

        int remainder = targetSum - num;

        if (remainder >= 0) {
            if (canSum(remainder, numbers)) {

                memo[targetSum] = true;

                return memo[targetSum];
            }
        }
 }

    memo[targetSum] = false;

    return memo[targetSum];
}

int main()
{
    int         n;
    int         targetSum;
    vector<int> numbers;

    cout << "Enter the number of elements in the array : ";
    cin >> n;

    numbers.resize(n);

    cout << "Enter the numbers in the array :";
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];

    cout << "Enter the target sum :";
    cin >> targetSum;

    memo.resize(targetSum + 1);

    if (canSum(targetSum, numbers))
        cout << "true";
    else
        cout<<"false";

	return 0;
}