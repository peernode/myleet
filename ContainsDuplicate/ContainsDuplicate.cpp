/*
* Contains Duplicate
* Date: 2015/11/2
* Tag: Array, Hash Table
* Difficulty: Easy
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i-1] == nums[i])
			{
				return true;
			}
		}

		return false;
	}
};

int main()
{
	vector<int> v{ 1,3,5,7,7,9 };
	Solution s;
	cout << "{1,3,5,7,7,9} is " << s.containsDuplicate(v) << endl;

	return 0;
}