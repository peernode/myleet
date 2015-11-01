/*
* House Robber
* Date: 2015/11/01
* Tag: Dynamic programming
* Difficulty: Easy
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
		int* dp = new int[nums.size() + 1];
		memset(dp, 0, 4 * (nums.size() + 1));
		dp[0] = 0;
		dp[1] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i + 1] = (dp[i - 1] + nums[i]) > dp[i] ? (dp[i - 1] + nums[i]) : dp[i];
		}

		return dp[nums.size()];
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1,2, 9,7 };
	cout << "{1,2,9,7}: " << s.rob(v) << endl;

	return 0;
}