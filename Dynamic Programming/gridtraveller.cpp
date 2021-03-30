//Say that you are a traveller on a 2D grid. You begin in the top left corner
//and your goal is to travel to the bottom-right corner. You may only move down or
//right.

//In how many ways can you travel to the goal of a grid with dimensions m*n ?

#include<iostream>
#include<vector>
using namespace std;

long long gridTraveller(int m, int n, vector<vector<long long>> & memo)
{
	if (memo[m][n] != 0)
		return memo[m][n];

	if (m == 0 || n == 0)
		return 1;

	memo[m][n] = gridTraveller(m - 1, n, memo) + gridTraveller(m, n - 1, memo);

	return memo[m][n];
}

int main()
{
	int							m, n;
	vector<vector<long long>>	memo;

	cout << "Enter the number of rows : ";
	cin >> m;

	cout << "Enter the number of rows : ";
	cin >> n;

	memo.resize(m, vector<long long>(n));

	cout << "Total number of ways to reach the destination are : " << gridTraveller(m-1, n-1, memo);

	return 0;
}