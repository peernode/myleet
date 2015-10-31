/*
* Climbing Stairs
* Date: 2015/10/31
* Tag: Dynamic Programming
* Difficulty: Easy
*/

#include <iostream>
using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n == 1) return 1;
		if (n == 2)return 2;

		int* d = new int[n];
		d[0] = 1;
		d[1] = 2;
		for (int i = 3; i <= n; ++i)
		{
			d[i-1] = d[i - 3] + d[i - 2];
		}

		return d[n-1];
	}
};

int main()
{
	Solution s;
	cout << "n=3: is " << s.climbStairs(3) << endl;
	cout << "n=5: is " << s.climbStairs(5) << endl;

	return 0;
}