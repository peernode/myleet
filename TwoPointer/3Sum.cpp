/*
* 3Sum
* Date: 2015/11/13
* Tag: Two pointer
* Difficulty: Medium
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ret;
		vector<int> vec(3);

		sort(nums.begin(), nums.end());

		int len = nums.size();
		for (int i = 0; i < len - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;  //avoid duplicates

			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				if(nums[i]+nums[j]+nums[k]==0)
				{
					vec[0] = nums[i];
					vec[1] = nums[j];
					vec[2] = nums[k];
					ret.push_back(vec);
					while (nums[j] == vec[1]) j++; //avoid duplicates
					while (nums[k] == vec[2])k--;  //avoid duplicates
				}
				else if (nums[i]+nums[j]+nums[k]>0)
				{
					k--;
				}
				else
				{
					j++;
				}
			}
		}

		return ret;
	}
};

int main()
{
	vector<int> nums{ -1,0,1,2,-1,4 };
	Solution s;
	vector<vector<int>> ret = s.threeSum(nums);
	for (int i = 0; i < ret.size(); ++i)
	{
		vector<int> v = ret[i];
		for (int j = 0; j < v.size(); ++j)
		{
			cout << " " << v[j];
		}

		cout << endl;
	}


	return 0;
}