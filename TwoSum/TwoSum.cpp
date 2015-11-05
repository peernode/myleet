/*
* Two Sum
* Date: 2015/11/5
* Tag:Array, Hash table
* Difficulty: Medium
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		map<int, int> value_pos_map;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (value_pos_map.find(target - nums[i]) != value_pos_map.end())
			{
				result.push_back(value_pos_map[target - nums[i]]);
				result.push_back(i + 1);
			}
			else
			{
				value_pos_map[nums[i]] = i + 1;
			}
		}

		return result;
	}
};


int main()
{
	vector<int> vec{ 2,7,11,15 };
	Solution s;
	vector<int> r = s.twoSum(vec, 9);
	if (!r.empty())
		cout << "first: " << r[0] << ", second: " << r[1] << endl;
	else
		cout << "null..." << endl;
	return 0;
}