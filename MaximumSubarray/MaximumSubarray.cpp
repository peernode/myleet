/*
* Maximum Subarray
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
	int maxSubArray(vector<int>& nums)
	{
		int gmax = nums[0];
		int local_max = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] >= (nums[i] + local_max))
			{
				local_max = nums[i];
			}
			else
			{
				local_max = nums[i] + local_max;
			}

			if (local_max > gmax)
			{
				gmax = local_max;
			}
		}

		return gmax;
	}
};

int main()
{
	vector<int> v{ -2, 1, -3, 4, -1, 2, 1, -5, -4 };
	Solution s;
	cout << "-2, 1, -3, 4, -1, 2, 1, -5, -4 is: " << s.maxSubArray(v) << endl;

	return 0;
}