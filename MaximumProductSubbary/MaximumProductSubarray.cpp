/*
* Maximum Product Subarray
* Date: 2015/11/2
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
	int maxProduct(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		int max_temp = nums[0];
		int min_temp = nums[0];
		int max_product = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			int a = max_temp * nums[i];
			int b = min_temp * nums[i];
			max_temp = max(nums[i], max(a, b));
			min_temp = min(nums[i], min(a, b));

			max_product = max(max_temp, max_product);
		}

		return max_product;
	}
};

int main()
{
	vector<int> v{ 2,3,-2,4 };
	Solution s;
	cout << "max product {2,3,-2,4}: " << s.maxProduct(v) << endl;

	return 0;
}