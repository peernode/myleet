/*
* Unique Binary Search Trees
* Date: 2015/10/31
* Tag: Tree, Dynamic Programming
* Difficulty: Medium
*/

#include <iostream>
using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		if (n == 1) return 1;
		int* d = new int[n+1];
		memset(d, 0, (n + 1)* sizeof(int));
		d[0] = 1;
		d[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				d[i] += d[j] * d[i - 1 - j];
			}
		}

		int r = d[n];
		delete[] d;
		return r;
	}
};

int main()
{
	Solution s;
	cout << "3 is:" << s.numTrees(3) << endl;
	cout << "5 is: " << s.numTrees(5) << endl;
	cout << "8 is:" << s.numTrees(8) << endl;

	return 0;
}