/*
* Remove Element
* Date: 2015/11/8
* Tag: Array, Two Pointers
* Difficulty: Easy
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int len = 0;
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			if (nums[l]==val)
			{
				nums[l] = nums[r];
				--r;
			}
			else
			{
				++l;
				++len;
			}
		}

		return len;
	}

};

int main()
{
	vector<int> v{ 1,2,5,7,5 };
	Solution s;
	cout << s.removeElement(v, 5) << endl;;
	return 0;
}