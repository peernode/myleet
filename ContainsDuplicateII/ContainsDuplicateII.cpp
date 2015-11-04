/*
* Contains Duplicate II
* Date: 2015/11/4
* Tag: Array, Hash Table
* Difficulty: Easy
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		map<int, int> value_pos_map;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (value_pos_map.find(nums[i])!=value_pos_map.end()) {
				if (i - value_pos_map[nums[i]] <= k) {
					return true;
				}
				value_pos_map[nums[i]] = i;
			}
			else
			{
				value_pos_map[nums[i]] = i;
			}
		}

		return false;
	}
};

int main()
{
	vector<int> v{ 1,2,3,1,4 };
	Solution s;
	cout << "1,2,3,1,4 and 1 : " << s.containsNearbyDuplicate(v, 3) << endl;

	return 0;
}