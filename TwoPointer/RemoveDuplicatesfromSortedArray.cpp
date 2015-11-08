/*
* Remove Duplicates from Sorted Array
* Date: 2015/11/8
* Tag: Array, Two pointer
* Difficulty: Easy
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int i = 0, j = 1;
		while (j < nums.size())
		{
			if (nums[j]!=nums[i])
			{
				nums[++i] = nums[j];
			}

			++j;
		}

		return i+1;
	}
};

int main()
{
	vector<int> vec{ 1,1,2 };
	Solution s;
	cout << s.removeDuplicates(vec) << endl;

	return 0;
}