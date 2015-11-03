/*
* Longest Increasing Subsequence
* Date: 2015/11/3
* Tag: Dynamic Programming
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		vector<int> dp(nums.size(), 1);

		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j]<nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		int max_dp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (dp[i]>max_dp)
			{
				max_dp = dp[i];
			}
		}

		return max_dp;
	}
};

int main()
{
	vector<int> vec{ 10, 9, 2, 5, 3, 7, 101, 18 };
	Solution s;
	cout << "10, 9, 2, 5, 3, 7, 101, 18 is: " << s.lengthOfLIS(vec) << endl;

	return 0;
}