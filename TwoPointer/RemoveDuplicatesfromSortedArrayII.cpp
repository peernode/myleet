/*
* Remove Duplicates from Sorted Array II
* Date: 2015/11/8
* Tag: two pointer
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int i = 0;
		for (int num : nums)
			if (i < 2 || num != nums[i - 2])
				swap(nums[i++], num);
		return i;

	}
};

int main()
{
	vector<int> vec{ 1,1,1,2,2,3 };
	Solution s;
	cout << s.removeDuplicates(vec) << endl;
	return 0;
}