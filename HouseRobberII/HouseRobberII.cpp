/*
* House Robber II
* Date: 2015/11/1
* Tag: Dynamic Programming
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		int max1 = sub_rob(&nums[0], nums.size() - 1);
		int max2 = sub_rob(&nums[1], nums.size() - 1);

		return max1>max2?max1:max2;
	}

	int sub_rob(int* a, int len)
	{
		int* dp = new int[len + 1];
		memset(dp, 0, 4 * (len + 1));
		dp[0] = 0;
		dp[1] = a[0];
		for (int i = 1; i < len; ++i)
		{
			dp[i + 1] = (dp[i - 1] + a[i]) > dp[i] ? (dp[i - 1] + a[i]) : dp[i];
		}

		return dp[len];
	}


};

int main()
{
	Solution s;
	vector<int> v{ 1,2, 9,7 };
	cout << "{1,2,9,7}: " << s.rob(v) << endl;

	return 0;
}